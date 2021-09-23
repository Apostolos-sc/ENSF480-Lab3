/*
 * File Name: Point.h
 * Assignment: Lab 1 Exercise D
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#ifndef POINT_H
#define POINT_H
#include <iostream>
class Point
{
    private:
        double x; // x coordinate of a location on Cartisian Plain
        double y; // y coordinate of a location on Cartisian Plain
        friend class Human;
        //setters
        // private so human can access these setters, but they're hidden
        void set_y(const double);
        void set_x(const double);
    public:
        Point();
        Point(const double, const double);
        //getters
        double get_x() const;
        double get_y() const;
};

#endif
