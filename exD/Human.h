/*
 * File Name: Human.h
 * Assignment: Lab 1 Exercise D
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#ifndef HUMAN_H
#define HUMAN_H
#include <cstring>
#include "Point.h"
class Human {
    protected:
        Point location; // Location of an object of Human on a Cartisian Plain
        char *name;     // Human's name
    public:
        //constructors
        Human();
        Human(const Human&);
        Human(const char*);
        Human(const char *nam = "", const double x = 0, const double y = 0);
        ~Human(); //destructor
        Human& operator =(const Human&);

        //getters
        const char *get_name() const;
        // TODO: const return?
        Point get_point() const;

        //setters
        void set_x(const double);
        void set_y(const double y);
        void set_name(const char *);

        virtual void display();
};

#endif
