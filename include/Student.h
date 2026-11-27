#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string surname;   // фамилия и инициалы
    int group;             // номер группы
    int* grades;           // успеваемость (динамический массив)
    int gradesCount;       // количество оценок

public:
    static const int MAX_GRADES = 20;
    static const int MIN_GRADE = 2;
    static const int MAX_GRADE = 5;

    Student();
    Student(const std::string& surname, int group, const int* grades, int gradesCount);
    Student(const Student& other);
    ~Student();

    Student& operator=(const Student& other);

    // get
    std::string getSurname() const;
    int getGroup() const;
    int getGradesCount() const;
    int getGrade(int index) const;
    const int* getGrades() const;

    // set
    void setSurname(const std::string& surname);
    void setGroup(int group);
    void setGrades(const int* grades, int count);
    void setGrade(int index, int value);

    double getAverage() const;          // средний балл
    bool hasOnlyGoodGrades() const;     // все оценки только 4 и 5

    friend std::istream& operator>>(std::istream& is, Student& student);
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif