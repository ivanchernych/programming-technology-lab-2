#ifndef MENU_H
#define MENU_H

#include "StudentList.h"
#include "TextProcessor.h"
#include <string>

class Menu {
private:
    StudentList list;           // студенты (задание 1)
    TextProcessor processor;    // работа с файлом (задание 2)

    void showMenu() const;

    void showAll() const;
    void addToEnd();
    void addAtPosition();
    void editStudent();
    void removeStudent();
    void sortStudents();
    void showGoodStudents() const;

    void setFileName();
    void showSentences() const;

public:
    Menu();
    Menu(const std::string& fileName);
    Menu(const Menu& other);
    ~Menu();

    void run();
};

#endif