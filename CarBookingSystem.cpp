#include "CarBookingSystem.h"
#include<string>
#include <queue>
#include <algorithm> //for string transformation functions

//constructor definition
CarBookingSystem::CarBookingSystem() {
    capacity = 20;
    bookings = new CarBooking[capacity];
    size = 0;

}

//destructor definition
CarBookingSystem::~CarBookingSystem() {
    delete[] bookings;
}

//function to add a booking
void CarBookingSystem::addBooking(const CarBooking& booking) {
    // Check capacity and resize if needed
    if (size >= capacity) {
        capacity *= 2; // Double the capacity
        CarBooking* newBookings = new CarBooking[capacity]; // Create a new array with the increased capacity
        for (int i = 0; i < size; ++i) {
            newBookings[i] = bookings[i]; // Copy existing bookings to the new array
        }
        delete[] bookings; // Deallocate memory for the old array
        bookings = newBookings; // Update bookings to point to the new array
    }

    bookings[size++] = booking; // Add the new booking and increment the size
    bookingQueue.push(booking);
}

//function to edit a booking
void CarBookingSystem::editBooking(const string& bookingId, const CarBooking& newBooking) {
    // Update the booking in the array-based storage
    for (int i = 0; i < size; ++i) {
        if (bookings[i].getBookingId() == bookingId) {
            bookings[i] = newBooking;
            break;
        }
    }

    // Update the corresponding booking in the queue
    queue<CarBooking> tempQueue;
    while (!bookingQueue.empty()) {
        CarBooking currentBooking = bookingQueue.front();
        bookingQueue.pop();

        if (currentBooking.getBookingId() == bookingId) {
            tempQueue.push(newBooking);
        }
        else {
            tempQueue.push(currentBooking);
        }
    }
    bookingQueue = tempQueue;
}


//function to delete a booking
void CarBookingSystem::deleteBooking(const std::string& bookingId) {
    // Delete the booking from the array-based storage
    for (int i = 0; i < size; ++i) {
        if (bookings[i].getBookingId() == bookingId) {
            for (int j = i; j < size - 1; ++j) {
                bookings[j] = bookings[j + 1];
            }
            size--;
            break;
        }
    }

    // Remove the corresponding booking from the queue
    queue<CarBooking> tempQueue;
    while (!bookingQueue.empty()) {
        if (bookingQueue.front().getBookingId() != bookingId) {
            tempQueue.push(bookingQueue.front());
        }
        bookingQueue.pop();
    }
    bookingQueue = tempQueue;
}

//function to search for a booking
CarBooking* CarBookingSystem::searchBooking(const string& bookingId) {
    //convert bookingId to uppercase (or lowercase)
    string searchId = bookingId;
    transform(searchId.begin(), searchId.end(), searchId.begin(), ::toupper); //convert to uppercase

    for (int i = 0; i < size; ++i) {
        //convert bookingId in the system to uppercase (or lowercase) for comparison
        string currentId = bookings[i].getBookingId();
        transform(currentId.begin(), currentId.end(), currentId.begin(), ::toupper); //convert to uppercase

        if (currentId == searchId) { //perform case-insensitive comparison
            return &bookings[i]; //return pointer to the found booking
        }
    }
    // Search for the booking in the queue
    queue<CarBooking> tempQueue = bookingQueue;
    while (!tempQueue.empty()) {
        if (tempQueue.front().getBookingId() == bookingId) {
            return &tempQueue.front();
        }
        tempQueue.pop();
    }
    return nullptr;
}


//function to get the size of bookings
int CarBookingSystem::getSize() const {
    return size;
}

//function to get a specific booking at an index
CarBooking* CarBookingSystem::getBooking(int index) {
    if (index >= 0 && index < size) {
        return &bookings[index];
    }
    return nullptr;
}