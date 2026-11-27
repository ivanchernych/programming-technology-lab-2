#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// Базовый класс всех исключений программы
class MyException : public std::exception {
protected:
    std::string message;

public:
    MyException();
    MyException(const std::string& message);
    MyException(const MyException& other);
    virtual ~MyException() noexcept;

    const char* what() const noexcept override;
    std::string getMessage() const;
    void setMessage(const std::string& message);
};

// Некорректный ввод пользователя (не число, значение вне допустимого диапазона и т.п.)
class InvalidInputException : public MyException {
public:
    InvalidInputException(const std::string& message);
    InvalidInputException(const InvalidInputException& other);
    ~InvalidInputException() noexcept;
};

// Выход за границы списка (несуществующая позиция / пустой список)
class IndexOutOfRangeException : public MyException {
public:
    IndexOutOfRangeException(const std::string& message);
    IndexOutOfRangeException(const IndexOutOfRangeException& other);
    ~IndexOutOfRangeException() noexcept;
};

// Ошибка работы с файлом (не найден, не открывается, имя не задано)
class FileOpenException : public MyException {
public:
    FileOpenException(const std::string& message);
    FileOpenException(const FileOpenException& other);
    ~FileOpenException() noexcept;
};

#endif