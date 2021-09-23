#include<Customer.h>
    //getters
    string Customer::getName() {
        return name;
    }
    string Customer::getPhone() {
        return phone;
    }
    string Customer::getAddress() {
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