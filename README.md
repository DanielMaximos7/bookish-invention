|Simple Contact Manager|

A lightweight command-line C++ application for managing contacts with CSV file persistence.

1. Add Contacts: Input name, phone, and email.

2. List Contacts: Display all saved entries.

3. Search Contacts: Find by partial or full name.

4. Delete Contacts: Remove by ID or exact name.

5. Persistence: Automatically load from and save to data/contacts.csv.

Quick Start:

Preliminary Steps: Prepare data directory
```
mkdir data
touch data/contacts.csv
```

2. Build
```
g++ -std=c++11 -o contact_manager contact_manager.cpp
```

3. Run
```
./contact_manager
```

Usage:
 - Choose an option from menu
 - Follow prompts to add, list, search, or delete contacts.
 -Exit to save changes back to data/contacts.csv.

Git

Added a .gitignore file to ignore the build folder
    contact_manager.exe