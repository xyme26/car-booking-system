#pragma once
#ifndef CARBOOKING_H
#define CARBOOKING_H

#include <string>
using namespace std;

class CarBooking {
private:
    string bookingId;
    string customerId; 
    string customerName;
    string carModel;

public:
    //constructors
    CarBooking(); //default constructor
    CarBooking(string bookingId, string userId, string userName, string carModel);

    //getters and setters
    string getBookingId() const;
    void setCustomerID(int custId);
    string getCustomerID() const;
    void setCustomerName(string name);
    string getCustomerName() const;
    void setCarModel(string model);
    string getCarModel() const;
};

#endif /* CARBOOKING_H */



