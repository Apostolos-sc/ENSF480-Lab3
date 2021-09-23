#include"Customer.h"
    //getters
    string Customer::getName() const {
        return name;
    }
    string Customer::getPhone() const {
        return phone;
    }
    string Customer::getAddress() const {
        return address;
    }
    //setters
    void Customer::setName(const string name) {
        this->name = name;
    }

    void Customer::setAddress(const string address) {
        this->address = address;
    }
    void Customer::setPhone(const string phone) {
        this->phone = phone;
    }
