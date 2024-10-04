#include <iostream>
#include <string>
#include "CarBookingSystem.h"
using namespace std;

int main() {
    
    //CarBookingSystem object
    CarBookingSystem bookingSystem;

    //flag to control program exit
    bool exitProgram = false;

    //input
    string name, id, bookingId, carModel, editId, newCarModel, deleteId, searchId;
    char newCustomer;

    //main loop
    do {

        cout << "Enter your customer ID: ";
        cin >> id;
        cin.ignore(); // Clear the newline character from the input buffer

        cout << "Enter your name: ";
        getline(cin, name);

        int choice;
        do {
            //display menu
            cout << "\n~~~~~~~~~~~~~~~Car Booking System~~~~~~~~~~~~~~~:\n";
            cout << "1. Add Booking\n";
            cout << "2. Edit Booking\n";
            cout << "3. Delete Booking\n";
            cout << "4. Search Booking\n";
            cout << "5. Display All Bookings\n";
            cout << "6. Finish or Exit\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // Clear the newline character from the input buffer

            switch (choice) {
            case 1: {
                cout << "Enter Booking ID: ";
                cin >> bookingId;
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Enter Car Model: ";
                getline(cin, carModel);

                // Create booking with user information
                CarBooking newBooking(bookingId, id, name, carModel);
                bookingSystem.addBooking(newBooking);
                cout << "Booking added successfully.\n";
                break;
            }

            case 2: {

                cout << "Enter booking ID to edit: ";
                cin >> editId;
                cin.ignore(); // Clear the newline character from the input buffer

                CarBooking* editBooking = bookingSystem.searchBooking(editId);
                if (editBooking != nullptr) {
                    cout << "Enter new car model: ";
                    getline(cin, newCarModel);

                    editBooking->setCarModel(newCarModel);
                    cout << "Booking edited successfully.\n";
                }
                else {
                    cout << "Booking not found.\n";
                }
                break;
            }

            case 3: {
                cout << "Enter booking ID to delete: ";
                cin >> deleteId;
                cin.ignore(); // Clear the newline character from the input buffer

                bookingSystem.deleteBooking(deleteId);
                cout << "Booking deleted successfully.\n";
                break;
            }

            case 4: {
                cout << "Enter booking ID to search: ";
                cin >> searchId;
                cin.ignore(); // Clear the newline character from the input buffer

                CarBooking* searchResult = bookingSystem.searchBooking(searchId);
                if (searchResult != nullptr) {
                    cout << "Booking found: ID: " << searchResult->getBookingId()
                        << ", Customer: " << searchResult->getCustomerName()
                        << ", Car Model: " << searchResult->getCarModel() << endl;
                }
                else {
                    cout << "Booking not found for ID: " << searchId << endl;
                }
                break;
            }

            case 5: {
                cout << "All Bookings:\n";
                for (int i = 0; i < bookingSystem.getSize(); ++i) {
                    CarBooking* booking = bookingSystem.getBooking(i);
                    cout << "ID: " << booking->getBookingId() << ", Customer: " << booking->getCustomerName()
                        << ", Car Model: " << booking->getCarModel() << endl;
                }
                break;
            }

            case 6:
                cout << "Finishing bookings for " << name << ".\n";
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }

            //exit the loop if user chooses choice 6 to finish or exit
            if (exitProgram || choice == 6) {
                break;
            }
        } while (!exitProgram); //inner loop for menu

        cout << "\nDo you want to book for another customer? (Y/N): ";
        cin >> newCustomer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer
        cout << endl;

        if (newCustomer != 'Y' && newCustomer != 'y') {
            cout << "Exiting Car Booking System. Thank you! Hope you have a nice day!!\n";
            break; //exit the program if no new customer want to book car
        }

    } while (true);

    return 0;
}

       
   