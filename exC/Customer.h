/*
 * File Name: Customer.h
 * Assignment: Lab 1 Exercise C
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;
class Customer{
    private:
        string name;
        string  phone;
        string address;
        friend class Company;
        friend class Employee;
    public:
        Customer();
        Customer(string, string, string);
        ~Customer();
        //getters
        string getName() const;
        string getPhone() const;
        string getAddress() const;
        //setters
        void setName(const string name);

        void setAddress(const string address);
        void setPhone(const string phone);
};

#endif
