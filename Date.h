
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date {
private:
    int month;
    int day;
    int year;

    int lastDay(int m, int y) const;
    bool isLeapYear(int y) const;

public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int m, int d, int y);

    // Accessors
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    bool isLeapYear() const;
    int lastDay() const;

    // String representations
    std::string toString1() const;
    std::string toString2() const;
    std::string toString3() const;

    // Operator overloads
    Date& operator++();    // Prefix increment
    Date operator++(int);  // Postfix increment
    Date& operator--();    // Prefix decrement
    Date operator--(int);  // Postfix decrement
    int operator-(const Date& other) const;  // Subtraction

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif
