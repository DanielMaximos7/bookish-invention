#include "ContactBook.h"
#include <iostream>

void printMenu() {

    std::cout << "\nContact Manager\n"
                << "1. List Contact\n"
                << "2. Add Contacts\n"
                << "3. Search Contacts\n"
                << "4. Delete Contact\n"
                << "5. Exit\n"
                << "Choose an option: ";
}

int main()
{
    ContactBook book("data/contacts.csv");

    int choice;
    do{
        printMenu(); std::cin >> choice;
        switch (choice){
            case 1: {
                for(auto& c : book.listContacts()) std::cout << c << '\n';
                break;
            }
            case 2: {
                std::cin.ignore(); // Clear the newline character from the input buffer
                std::string name, phone, email;
                std::cout << "Name: "; std::getline(std::cin, name);
                std::cout << "Phone: "; std::getline(std::cin, phone);
                std::cout << "Email: "; std::getline(std::cin, email);
                Contact c(book.searchContacts("").size() + 1, name, phone, email);
                book.addContact(c);
                break;

            }
            case 3: {
                std::cin.ignore();
                std::cout << "Search: ";
                std::string key; std::getline(std::cin, key);
                for (auto& c : book.searchContacts(key)) std::cout << c << '\n';
                break;
            }
            case 4: {
                std::cout << "Delete by ID: ";
                int id; std::cin >> id;
                if(!book.deleteContactById(id)) std::cout << "Not found.";
                break;
            }
            



            }
        }while(choice != 5);
        return 0;
    }
    


