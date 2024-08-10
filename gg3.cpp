#include <bits/stdc++.h>

using namespace std;

// Define a constant for phone number length
const int PHONE_NUMBER_LENGTH = 10;

struct Contact {
    string name;
    string phoneNumber;
};

class Solution {
public:
    // Function to remove duplicate contacts
    vector<Contact> removeDuplicates(vector<Contact>& contacts) {
        vector<Contact> uniqueContacts;
        if (!contacts.empty()) {
            uniqueContacts.push_back(contacts[0]);
            for (int i = 1; i < contacts.size(); i++) {
                bool duplicate = false;
                for (int k = 0; k < uniqueContacts.size(); k++) {
                    if (contacts[i].phoneNumber == uniqueContacts[k].phoneNumber) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) {
                    uniqueContacts.push_back(contacts[i]);
                }
            }
        }
        return uniqueContacts;
    }

    // Function to search for a contact by name
    void searchContact(const vector<Contact>& contacts, const string& name) {
        auto it = find_if(contacts.begin(), contacts.end(),
            [&name](const Contact& contact) { return contact.name == name; });
        if (it != contacts.end()) {
            cout << "Contact found: " << it->name << " - " << it->phoneNumber << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }
};

// Function to save contacts to a file
void saveToFile(const vector<Contact>& contacts) {
    ofstream file("contacts.txt");
    if (!file.is_open()) {
        throw runtime_error("Unable to open file for writing.");
    }
    for (const auto& contact : contacts) {
        file << contact.name << "," << contact.phoneNumber << endl;
    }
    file.close();
}

// Function to load contacts from a file
void loadFromFile(vector<Contact>& contacts) {
    ifstream file("contacts.txt");
    if (!file.is_open()) {
        return;
    }
    string line;
    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string name = line.substr(0, commaPos);
            string phoneNumber = line.substr(commaPos + 1);
            Contact contact = {name, phoneNumber};
            contacts.push_back(contact);
        }
    }
    file.close();
}

// Function to display file contents
void displayFileContents() {
    ifstream file("contacts.txt");
    if (!file.is_open()) {
        cout << "File not found or unable to open." << endl;
        return;
    }
    string line;
    bool isEmpty = true;
    while (getline(file, line)) {
        cout << line << endl;
        isEmpty = false;
    }
    if (isEmpty) {
        cout << "File is empty." << endl;
    }
    file.close();
}

int main() {
    system("cls");
    vector<Contact> contacts;
    loadFromFile(contacts);
    string phoneNumber;
    string name;
    int choice;
    Solution solution;

    // Collect contacts
    while (true) {
        cout << "1. Add number" << endl;
        cout << "2. View numbers" << endl;
        cout << "3. Remove duplicates" << endl;
        cout << "4. Save and Exit" << endl;
        cout << "5. Remove a number" << endl;
        cout << "6. Search a number" << endl;
        cout << "7. Exit without saving" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            cout << "Enter 10-digit phone numbers and names " << endl;
            cout << "Enter phone number: ";
            cin >> phoneNumber;

            if (phoneNumber.length() == PHONE_NUMBER_LENGTH && all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
                cout << "Enter name: ";
                cin.ignore(); // ignore newline character left in input buffer
                getline(cin, name);
                Contact contact = {name, phoneNumber};
                contacts.push_back(contact);
            } else {
                cout << "Invalid input. Please enter a 10-digit number." << endl;
            }
            cout << endl;
            break;

        case 2:
            if (contacts.empty()) {
                cout << "No contacts available." << endl;
            } else {
                for (const Contact &contact : contacts) {
                    cout << contact.name << ": " << contact.phoneNumber << endl;
                }
            }
            cout << endl;
            break;
            
        case 3:
            // Remove duplicates
            contacts = solution.removeDuplicates(contacts);
            cout << "Unique contacts:" << endl;
            for (const Contact &contact : contacts) {
                cout << contact.name << ": " << contact.phoneNumber << endl;
            }
            cout << endl;
            break;

        case 4:
            // Save and exit
            saveToFile(contacts);
            cout << "Contacts saved to file." << endl;
            cout << "Exiting..." << endl;
            cout << endl;
            return 0;

        case 5:
            // Remove a number
            cout << "Enter phone number to remove: ";
            cin >> phoneNumber;
            for (auto it = contacts.begin(); it != contacts.end(); ++it) {
                if (it->phoneNumber == phoneNumber) {
                    contacts.erase(it);
                    cout << "Number removed successfully." << endl;
                    cout << endl;
                    break;
                }
            }
            break;

        case 6:
            // Search a number
            cout << "Enter name to search: ";
            cin.ignore(); // ignore newline character left in input buffer
            getline(cin, name);
            solution.searchContact(contacts, name);
            cout << endl;
            break;

        case 7:
            // Exit without saving
            cout << "Exiting without saving..." << endl;
            cout << endl;
            return 0;

        default:
            cout << "Invalid input!" << endl;
        }
    }
    system("pause");
    return 0;
}
