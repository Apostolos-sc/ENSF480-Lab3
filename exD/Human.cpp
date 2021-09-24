/*
 * File Name: Human.cpp
 * Assignment: Lab 1 Exercise D
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#include <cstring>
#include <iostream>
#include "Human.h"

using namespace std;

Human::Human(const Human& src): name(new char[strlen(src.get_name())] + 1) {
    strcpy(this -> name, src.get_name());

    const double x = src.get_point().get_x();
    const double y = src.get_point().get_y();
    location.set_x(x);
    location.set_y(y);
}
Human::Human(const char * nam) {
    location.set_x(0);
    location.set_y(0);
    name = new char[strlen(nam) + 1];
    strcpy(this->name, nam);
}

Human::Human(const char *nam, const double a, const double b) {
    location.set_x(a);
    location.set_y(b);
    name = new char[strlen(nam) + 1];
    strcpy(this->name, nam);
}

Human::~Human() {
    delete [] name;
}

Human& Human::operator=(const Human& src) {
    delete [] name;
    name = new char[strlen(src.get_name()) + 1];
    strcpy(name, src.get_name());

    const double x = src.get_point().get_x();
    const double y = src.get_point().get_y();
    location.set_x(x);
    location.set_y(y);

    return *this;
}

const char *Human::get_name() const { 
    return name; 
}

void Human::set_name(const char *name) {
    location.set_x(0);
    location.set_y(0);
    delete []name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Point Human::get_point() const { 
    return location; 
}

void Human::set_x(const double x) {
    location.set_x(x);
}

void Human::set_y(const double y) {
    location.set_y(y);
}

void Human::display()
{
    cout << "Human Name: " << name << "\nHuman Location: "
        << location.get_x() << " ,"
        << location.get_y() << ".\n"
        << endl;
}
