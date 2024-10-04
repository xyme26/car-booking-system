#ifndef CARBOOKINGSYSTEM_H
#define CARBOOKINGSYSTEM_H

#include "CarBooking.h"
#include <string>
#include <queue>

class CarBookingSystem {
private:
    CarBooking* bookings;
    int capacity;
    int size;
    std::queue<CarBooking> bookingQueue; //Add a queue to manage bookings

public:
    CarBookingSystem();
    ~CarBookingSystem();

    void addBooking(const CarBooking& booking);
    void editBooking(const std::string& bookingId, const CarBooking& newBooking); // Update parameter type to std::string
    void deleteBooking(const std::string& bookingId); // Update parameter type to std::string
    CarBooking* searchBooking(const std::string& bookingId); // Update parameter type to std::string
    CarBooking* getNextBooking(); //Method to get the next booking from the queue
    int getSize() const;
    CarBooking* getBooking(int index);
};

#endif /* CARBOOKINGSYSTEM_H */



