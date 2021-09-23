/*
 * File Name: Company.h
 * Assignment: Lab 1 Exercise C
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <vector>
#include "Employee.h"
#include "Customer.h"
using namespace std;

// we are trying to refactor. Let's use classes instead right??
class Company {
    private:
        string name;
        string address;
        vector<Employee> employees;
        string dateEstablished;
        vector<Customer> customers;
};

#endif
