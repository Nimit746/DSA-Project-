# Contact Management System in C++

* This C++ code implements a simple contact management system that allows users to add, view, remove duplicates, save, and exit the program. The system uses a Contact struct to represent individual contacts, which consist of a name and a phoneNumber.

 Key Features:

1. Add Contact: Users can add new contacts by entering a 10-digit phone number and a corresponding name.
2. View Contacts: Users can view all existing contacts in the system.
3. Remove Duplicates: The system can remove duplicate contacts based on phone numbers.
4. Save and Exit: Users can save all contacts to a file named "contacts.txt" and exit the program.
5. Remove a Contact: Users can remove a specific contact by entering the corresponding phone number.
6. Exit without Saving: Users can exit the program without saving any changes.

Implementation Details: 

1. The Contact struct represents individual contacts with name and phoneNumber members.
2. The Solution class provides a removeDuplicates function to remove duplicate contacts from a vector of contacts.
3. The saveToFile function saves all contacts to a file named "contacts.txt".
4. The main function implements the program's menu-driven interface, allowing users to interact with the contact management system.

Helper Functions:

1. selectRandomName: a function to select a random name from a vector of names (not used in this implementation).
2. removeDuplicates: a function to remove duplicate contacts from a vector of contacts.
3. saveToFile: a function to save all contacts to a file named "contacts.txt".

Notes:

1. The program uses a simple text-based interface and does not perform any error checking on user input beyond ensuring that phone numbers are 10 digits long and contain only digits.
2. The program does not handle cases where the user attempts to remove a contact that does not exist.
3. The program uses a system("cls") call to clear the console screen, which may not work on all platforms.
