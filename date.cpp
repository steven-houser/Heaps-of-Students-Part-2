// Name: Steven Houser
// Project: Lab 8 - Heap of Students Part 2
// Date: 03/06/26

#include <iostream>
#include <sstream>
#include "date.h"

// Default constructor - safe default values
Date::Date() {
    month = 0;
    day = 0;
    year = 0;
} // end constructor

// Parse MM/DD/YYYY string into month, day, year integers
void Date::init(std::string dateStr) {
    std::stringstream ss;
    std::stringstream converter;
    std::string sMonth;
    std::string sDay;
    std::string sYear;

    // Load date string into parsing stream
    ss.str(dateStr);

    // Extract tokens using slash delimiter
    getline(ss, sMonth, '/');
    getline(ss, sDay, '/');
    getline(ss, sYear);

    // Convert string tokens to integers
    converter << sMonth;
    converter >> month;
    converter.clear();
    converter.str("");

    converter << sDay;
    converter >> day;
    converter.clear();
    converter.str("");

    converter << sYear;
    converter >> year;
} // end init

// Print date in MM/DD/YYYY format
void Date::printDate() {
    std::cout << month << "/" << day << "/" << year << std::endl;
} // end printDate
