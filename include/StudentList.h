#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include <iostream>

// Динамический список студентов (массив указателей, без STL-контейнеров)
class StudentList {
private:
    Student** items;
    int count;
    int capacity;

    void grow();

public:
    StudentList();
    StudentList(int capacity);
    StudentList(const StudentList& other);
    ~StudentList();

    StudentList& operator=(const StudentList& other);
    Student& operator[](int index);
    const Student& operator[](int index) const;

    int getCount() const;

    void addToEnd(const Student& student);
    void insert(int index, const Student& student);   // index: 0..count
    void remove(int index);                           // index: 0..count-1
    void sortByAverage();                             // по возрастанию среднего балла
    void printGoodStudents() const;                   // фамилии и группы студентов с оценками 4 и 5

    friend std::ostream& operator<<(std::ostream& os, const StudentList& list);
};

#endif