/*
 * File Name: Point.cpp
 * Assignment: Lab 1 Exercise D
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#include "Point.h"
//constructors
Point::Point() : x(0), y(0) {}
Point::Point(const double a, const double b) : x(a), y(b) {}
//getters
double Point::get_x() const {
    return x;
}
double Point::get_y() const {
    return y;
}
//setters
void Point::set_x(const double a) {
    x = a;
}
void Point::set_y(const double a) {
    y = a;
}
