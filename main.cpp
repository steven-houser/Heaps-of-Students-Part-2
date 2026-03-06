// Name: Steven Houser
// Project: Lab 8 - Heap of Students Part 2
// Date: 03/06/26

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

bool sortByLast(Student* a, Student* b);
bool sortByFirst(Student* a, Student* b);
bool sortByCreditsDesc(Student* a, Student* b);

int main() {
    std::vector<Student*> students;

    loadStudents(students);

    std::string choice;
    do {
        choice = menu();
        if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students);
        } else if (choice == "4") {
            std::sort(students.begin(), students.end(), sortByLast);
            showStudentNames(students);
        } else if (choice == "5") {
            std::sort(students.begin(), students.end(), sortByFirst);
            showStudentNames(students);
        } else if (choice == "6") {
            std::sort(students.begin(), students.end(), sortByCreditsDesc);
            showStudentNames(students);
        } else if (choice != "0") {
            std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != "0");

    delStudents(students);
    return 0;
} // end main

// Load students from CSV file into vector
void loadStudents(std::vector<Student*>& students) {
    std::ifstream infile;
    std::string currentLine;

    infile.open("students.csv");

    while (getline(infile, currentLine)) {
        if (currentLine.empty()) {
            continue;
        }
        Student* s = new Student();
        s->init(currentLine);
        students.push_back(s);
    }

    infile.close();
} // end loadStudents

// Print all student names (Last, First)
void showStudentNames(std::vector<Student*>& students) {
    for (Student* student : students) {
        std::cout << student->getLastFirst() << std::endl;
    }
} // end showStudentNames

// Print full data for all students
void printStudents(std::vector<Student*>& students) {
    for (Student* student : students) {
        student->printStudent();
        std::cout << std::endl;
    }
} // end printStudents

// Search by last name (partial match)
void findStudent(std::vector<Student*>& students) {
    std::string searchTerm;
    std::cout << "Enter search term (last name): ";
    getline(std::cin, searchTerm);

    for (Student* student : students) {
        if (student->getLastName().find(searchTerm) != std::string::npos) {
            student->printStudent();
            std::cout << std::endl;
        }
    }
} // end findStudent

// Free all heap-allocated students
void delStudents(std::vector<Student*>& students) {
    for (Student* student : students) {
        delete student;
    }
    students.clear();
} // end delStudents

// Display menu and return user choice
std::string menu() {
    std::cout << "0) quit" << std::endl;
    std::cout << "1) print all student names" << std::endl;
    std::cout << "2) print all student data" << std::endl;
    std::cout << "3) find a student" << std::endl;
    std::cout << "4) sort by last name" << std::endl;
    std::cout << "5) sort by first name" << std::endl;
    std::cout << "6) sort by credit hours (descending)" << std::endl;
    std::cout << "Choice: ";

    std::string choice;
    getline(std::cin, choice);
    return choice;
} // end menu

// Comparator: sort by last name
bool sortByLast(Student* a, Student* b) {
    return a->getLastName() < b->getLastName();
} // end sortByLast

// Comparator: sort by first name
bool sortByFirst(Student* a, Student* b) {
    return a->getFirstName() < b->getFirstName();
} // end sortByFirst

// Comparator: sort by credit hours descending
bool sortByCreditsDesc(Student* a, Student* b) {
    return a->getCreditHours() > b->getCreditHours();
} // end sortByCreditsDesc
