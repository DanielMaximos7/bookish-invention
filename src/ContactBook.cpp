#include "ContactBook.h"
#include <fstream>
#include <sstream>
#include <algorithm>

ContactBook::ContactBook(const std::string& filename)
    : filename_(filename), nextId_(1) {load();}


ContactBook::~ContactBook(){ save();}

void ContactBook::load() {
    std::ifstream in (filename_);
    std::string line;

    while(std::getline(in, line)){
        if(!line.empty()) contacts_.push_back(Contact::deserialization(line));
    }

    updateNextId();
}

void ContactBook::save() const {
    std::ofstream out(filename_);
    for(auto& c : contacts_) out << c.serialize() << "\n";
}

void ContactBook::addContact(const Contact& contact){
    contacts_.push_back(contact);
    nextId_ = std::max(nextId_, contact.getId() + 1);
}

std::vector<Contact> ContactBook::listContacts() const { return contacts_; };

std::vector<Contact> ContactBook::searchContacts(const std::string& keyword) const {
    std::vector<Contact> results;
    for (auto& c : contacts_) if (c.getName().find(keyword) != std::string::npos) results.push_back(c);
    return results;

}

bool ContactBook::deleteContactById(int id){
    auto it = std::remove_if(contacts_.begin(), contacts_.end(),[id](auto& c){ return c.getId() == id;});
    
    if(it == contacts_.end()) return false; // No contact found with that ID
    contacts_.erase(it, contacts_.end());
    return true;
}


bool ContactBook::deleteContactByName(const std::string& name){
    auto it = std::remove_if(contacts_.begin(), contacts_.end(), [name](auto& c) {return c.getName() == name;});

    if(it == contacts_.end()) return false; // No contact found with that name
    contacts_.erase(it, contacts_.end());
    return true;
}

void ContactBook::updateNextId(){
    for (auto& c : contacts_) nextId_ = std::max(nextId_, c.getId() + 1);
}


