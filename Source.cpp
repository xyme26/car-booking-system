//CarBooking.cpp
#include "CarBooking.h"
using namespace std;

// Default constructor definition
CarBooking::CarBooking() : bookingId(""), customerId(""), customerName(""), carModel("") {}

// Parameterized constructor definition
CarBooking::CarBooking(string id, string custId, string name, string model)
    : bookingId(id), customerId(custId), customerName(name), carModel(model) {}


// Getter and setter definitions
string CarBooking::getBookingId() const {
    return bookingId; 
}

void CarBooking::setCustomerID(int custId) {
    customerId = custId;
}

string CarBooking::getCustomerID() const {
    return customerId;
}

void CarBooking::setCustomerName(std::string name) {
    customerName = name;
}

string CarBooking::getCustomerName() const {
    return customerName;
}

void CarBooking::setCarModel(string model) {
    carModel = model;
}

string CarBooking::getCarModel() const {
    return carModel;
}


