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