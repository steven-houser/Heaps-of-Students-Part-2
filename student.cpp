// Name: Steven Houser
// Project: Lab 8 - Heap of Students Part 2
// Date: 03/06/26

#include <iostream>
#include <sstream>
#include "student.h"

// Default constructor - allocate heap members
Student::Student() {
    first = "";
    last = "";
    address = new Address();
    dateOfBirth = new Date();
    expectedGraduation = new Date();
    credits = 0;
} // end constructor

// Destructor - free heap members
Student::~Student() {
    delete address;
    delete dateOfBirth;
    delete expectedGraduation;
} // end destructor

// Parse comma-delimited CSV string into student fields
// Format: first,last,street,city,state,zip,birthdate,graddate,credits
void Student::init(std::string csvLine) {
    std::stringstream ss;
    std::string sCredits;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string birthStr;
    std::string gradStr;
    std::stringstream converter;

    // Load CSV line into parsing stream
    ss.str(csvLine);

    // Extract each field using comma delimiter
    getline(ss, first, ',');
    getline(ss, last, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');
    getline(ss, birthStr, ',');
    getline(ss, gradStr, ',');
    getline(ss, sCredits);

    // Initialize address with extracted fields
    address->init(street, city, state, zip);

    // Initialize date objects with extracted strings
    dateOfBirth->init(birthStr);
    expectedGraduation->init(gradStr);

    // Convert credits string to integer
    converter << sCredits;
    converter >> credits;
} // end init

// Print all student data
void Student::printStudent() {
    std::cout << last << ", " << first << std::endl;
    address->printAddress();
    std::cout << "Born: ";
    dateOfBirth->printDate();
    std::cout << "Grad: ";
    expectedGraduation->printDate();
    std::cout << "Credits: " << credits << std::endl;
} // end printStudent

// Return last, first formatted string
std::string Student::getLastFirst() {
    return last + ", " + first;
} // end getLastFirst

// Return last name
std::string Student::getLastName() {
    return last;
} // end getLastName

// Return first name
std::string Student::getFirstName() {
    return first;
} // end getFirstName

// Return credit hours
int Student::getCreditHours() {
    return credits;
} // end getCreditHours
