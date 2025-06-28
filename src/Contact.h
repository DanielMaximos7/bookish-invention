#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>


class Contact{
    public:
        Contact() = default;
        Contact(int id, const std::string& name, const std::string& phone, const std::string & email);

        int getId() const;

        //const (constant): read only and cannot be modified. 
        //Getters return a constant reference to the string, and cannot be changed through the getter.
        //contact.getName() = "new name"; // ERROR - can't modify a constant reference
        //without const, it would possible to modify the string directly through the reference
        const std::string& getName() const;
        const std::string& getPhone() const;
        const std::string& getEmail() const;

        //Mutators
        void setName(const std::string& name);
        void setPhone(const std::string& phone);
        void setEmail(const std::string& email);

        std::string serialize() const;
        static Contact deserialization(const std::string& line);

        friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

    private:
        int _id;
        std::string name_;
        std::string phone_;
        std::string email_;

};
#endif // CONTACT_H
