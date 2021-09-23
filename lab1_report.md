# ENSF 480 Lab 1 Report

## Cover Page

**Names:** Beau McCartney, Apostolos Scondriannis

**Course Name:** Principles of Software Design

**Lab Section:** B02 (Dr. Moshirpour)

**Course Code:** ENSF 480 Fall 2021

**Assignment Number:** Lab 1

**Submission Date and Time:** 24/09/2021

## Exercise Solutions

### Exercise A
![exA answer table 1](img\exA1.png)
![exA answer table 2](img\exA2.png)

### Exercise B
![exB AR diagram](img\exB.jpg)

#### Code
```c++
/*
 * File Name: dictionaryList.cpp
 * Assignment: Lab 1 Exercise B
 * Completed By: Beau McCartney, Apostolos Scondriannis
 * Submission Date: September 24th, 2021
 */

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
    if (sizeM == 0) {
        cursorM = 0;
        return;
    } 

    Node *p;
    for(p = headM; p != 0 && p -> keyM < keyA; p = p -> nextM)
        ;
    
    cursorM = p != 0 && p -> keyM == keyA ? p : 0
}


void DictionaryList::destroy()
{
  if (sizeM > 0) {
      for (Node *temp = headM->nextM; temp != 0; temp = temp -> nextM) {
          delete headM;
          headM = temp;
      }
      delete headM;

      sizeM = 0;
  } 
  headM = 0;
}


void DictionaryList::copy(const DictionaryList& source)
{
    sizeM = 0;
    headM = 0;

    Node *src = source.headM;

    while (src != 0)
    {
        const Key keyN = src->keyM;
        const Datum datumN = src->datumM;
        insert(keyN, datumN);

        src = src->nextM;
    }

    if (source.cursor_ok()) {
        Key cursorKey = source.cursor_key();
        find(cursorKey);
    }

    assert(sizeM == source.size());
}
```

### Exercise C

#### Code 
```c++

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
    public:
        //constructors
        Company();
        Company(string, string, string);
        Company(string, string);
        Company(const Company& source);
        ~Company(); //destructor

        //getters
        string getName() const;
        string getAddress() const;
        string getDateEstablished() const;
        vector<string> getEmployees() const;
        
};

#endif

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
    public:
        Employee();
        Employee(string, string, EmployeeState);
        Employee(const Employee&);
        ~Employee();
        //getters
        string getName() const;
        string getAddress() const;
        EmployeeState getEmployeeState() const;
        //setters
};

#endif

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
```

### Exercise D

#### Code

```c++

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
        Human(const char*);
        Human(const char *nam = "", const double x = 0, const double y = 0);
        ~Human(); //destructor

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

Human::Human() {
    location.set_x(0);
    location.set_y(0);
    name = new char[1];
    strcpy(this->name, "");
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
    delete []name;
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

```
