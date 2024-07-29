#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <random>
#include <string>
#include <fstream>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

// Function to select a random name
string selectRandomName(const vector<string>& names) {
    if (names.empty()) {
        return "";
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, names.size() - 1);
    int randomIndex = distrib(gen);

    return names[randomIndex];
}

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
};

void saveToFile(const vector<Contact>& contacts) {
    ofstream file("contacts.txt");
    if (!file.is_open()) return;
    for (const Contact& contact : contacts) {
        file << contact.name << "," << contact.phoneNumber << endl;
    }
    file.close();
}

int main() {
    system("cls");
    vector<Contact> contacts;
    string phoneNumber;
    string name;
    int choice;
    Solution solution;

    // Collect contacts
    while (true) {
        cout << "1. Add number\n";
        cout << "2. View numbers\n";
        cout << "3. Remove duplicates\n";
        cout << "4. Save and Exit\n";
        cout << "5. Remove a number\n";
        cout << "6. Exit without saving\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter 10-digit phone numbers and names " << endl;
                cout << "Enter phone number: ";
                cin >> phoneNumber;

                if (phoneNumber.length() == 10 && all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
                    cout << "Enter name: ";
                    cin.ignore(); // ignore newline character left in input buffer
                    getline(cin, name);
                    Contact contact = {name, phoneNumber};
                    contacts.push_back(contact);
                } else {
                    cout << "Invalid input. Please enter a 10-digit number." << endl;
                }
                break;

            case 2:
                // Print all contacts
                cout << "All contacts:" << endl;
                for (const Contact& contact : contacts) {
                    cout << contact.name << ": " << contact.phoneNumber << endl;
                }
                break;

            case 3:
                // Remove duplicates
                contacts = solution.removeDuplicates(contacts);
                cout << "Unique contacts:" << endl;
                for (const Contact& contact : contacts) {
                    cout << contact.name << ": " << contact.phoneNumber << endl;
                }
                break;

            case 4:
                // Save and exit
                saveToFile(contacts);
                cout << "Contacts saved to file." << endl;
                cout << "Exiting..." << endl;
                return 0;

            case 5:
                // Remove a number
                cout << "Enter phone number to remove: ";
                cin >> phoneNumber;
                for (auto it = contacts.begin(); it != contacts.end(); ++it) {
                    if (it->phoneNumber == phoneNumber) {
                        contacts.erase(it);
                        cout << "Number removed successfully." << endl;
                        break;
                    }
                }
                break;
            case 6:
                cout << "Exiting...." << endl;
                return 0; 

            default:
                cout << "Invalid input!" << endl;
        }
    }
    system ("pause");
    return 0;
}
