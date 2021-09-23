/*
 * File Name: Employee.h
 * Assignment: Lab 1 Exercise C
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

enum EmployeeState {
    ACTIVE, SUSPENDED, RETIRED, FIRED
};

class Employee {
    private:
        string name;
        string address;
        EmployeeState state;
        friend class Company;
};

#endif
