#include "Contact.h"
#include <sstream>

/*
When you don't use a member initializer list, C++ automatically default-constructs all member variables 
(strings become empty `""`, ints get garbage values) before your constructor body runs, then you assign over those default values.

*/
//Constructor implementation
Contact::Contact(int id, const std::string& name, const std::string& phone, const std::string& email)
    :_id(id), name_(name), phone_(phone), email_(email) {}

/*
std::string data = contact.serialize();  // Gets a copy
data += " extra info";                   // Can modify the returned string
data.clear();                           // Can clear it too

The const at the end = "this function is read-only and won't change 
the Contact object" The return type = "gives you a modifiable copy of a string"
*/
// Accessors
int Contact::getId() const {
    return _id;
}

const std::string& Contact::getName() const {
    return name_;
}

const std::string& Contact::getPhone() const {
    return phone_;
}

const std::string& Contact::getEmail() const {
    return email_;
}

// Mutators
void Contact::setName(const std::string& name) {
    name_ = name;
}

void Contact::setPhone(const std::string& phone) {
    phone_ = phone;
}

void Contact::setEmail(const std::string& email) {
    email_ = email;
}

std::string Contact::serialize() const{
    std::ostringstream oss;
    oss << _id << "," << name_ << "," << phone_ << "," << email_;
    return oss.str();
};

Contact Contact::deserialization(const std::string& line){
    std::istringstream iss(line);
    std::string token;

    int id; std::string name, phone, email;
    std::getline(iss, token, ','); id = std::stoi(token);
    std::getline(iss, name, ',');
    std::getline(iss, phone, ',');
    std::getline(iss, email, ',');
    return Contact(id, name, phone, email);
    
}
//operator<< means "if someone tries to insert a Contact object using <<, here's what you do."
std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << "[" << contact._id << "]"
    << contact.name_ << " | "
    << contact.phone_ << " | "
    << contact.email_ ;
    return os;
}