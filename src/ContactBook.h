#ifndef _CONTACTBOOK_H
#define _CONTACTBOOK_H
#include <vector>
#include <string>
#include "Contact.h"

class ContactBook{
    public:

        explicit ContactBook(const std::string& filename);
        ~ContactBook();

        void load();
        void save() const;

        void addContact(const Contact& contact);
        std::vector<Contact> listContacts() const;
        std::vector<Contact> searchContacts(const std::string& keword) const;

        bool deleteContactById(int id);
        bool deleteContactByName(const std::string& name);
        
        private:
            std::vector<Contact> contacts_;
            std::string filename_;
            int nextId_;

            void updateNextId();
            

};


#endif // _CONTACTBOOK_H