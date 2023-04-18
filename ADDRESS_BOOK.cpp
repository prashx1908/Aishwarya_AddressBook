#include <iostream>
#include <string>
#include <vector>

using namespace std;

// define a struct to hold contact information
struct Contact {
    string name;
    string address;
    string phone;
    string email;
};

// function to add a new contact
void addContact(vector<Contact>& addressBook) {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter address: ";
    getline(cin, newContact.address);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email: ";
    getline(cin, newContact.email);
    addressBook.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

// function to display all contacts
void displayContacts(const vector<Contact>& addressBook) {
    if (addressBook.empty()) 
    {
        cout << "Address book is empty." << endl;
        return;
    }
    cout << "Address Book:" << endl;
    for (const auto& contact : addressBook) {
        cout << "Name: " << contact.name << endl;
        cout << "Address: " << contact.address << endl;
        cout << "Phone: " << contact.phone << endl;
        cout << "Email: " << contact.email << endl;
        cout << endl;
    }
}

// function to search for a contact by name
void searchByName(const vector<Contact>& addressBook) {
    string nameToFind;
    cout << "Enter name to search: ";
    getline(cin, nameToFind);
    bool found = false;
    for (const auto& contact : addressBook) {
        if (contact.name == nameToFind) {
            cout << "Contact Found:" << endl;
            cout << "Name: " << contact.name << endl;
            cout << "Address: " << contact.address << endl;
            cout << "Phone: " << contact.phone << endl;
            cout << "Email: " << contact.email << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}

int main() {
    vector<Contact> addressBook;
    while (true) {
        cout << "Address Book Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Search By Name" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter choice (1-4): ";
        cin >> choice;
        cin.ignore(); // to consume the newline character
        cout << endl;
        switch (choice) {
            case 1:
                addContact(addressBook);
                break;
            case 2:
                displayContacts(addressBook);
                break;
            case 3:
                searchByName(addressBook);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}