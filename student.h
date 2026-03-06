#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <string>
#include "date.h"
#include "address.h"

class Student {
private:
    std::string first;
    std::string last;
    Address* address;
    Date* dateOfBirth;
    Date* expectedGraduation;
    int credits;

public:
    Student();
    ~Student();
    void init(std::string csvLine);
    void printStudent();
    std::string getLastFirst();
    std::string getLastName();
    std::string getFirstName();
    int getCreditHours();
};

#endif
