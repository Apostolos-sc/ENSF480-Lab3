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


class Employee {
    enum State {
        ACTIVE, SUSPENDED, RETIRED, FIRED
    };

    private:
        string name;
        string address;
        State state;
        friend class Company;
};

#endif
