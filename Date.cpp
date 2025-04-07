
#include "Date.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

static std::string getMonthName(int m) {
    switch (m) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "";
    }
}

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
    if (m < 1 || m > 12) {
        std::cout << "Invalid month\n";
        month = 1; day = 1; year = 1900;
        return;
    }
    if (y < 1) {
        std::cout << "Invalid year\n";
        month = 1; day = 1; year = 1900;
        return;
    }
    int maxDay = lastDay(m, y);
    if (d < 1 || d > maxDay) {
        std::cout << "Invalid day\n";
        month = 1; day = 1; year = 1900;
        return;
    }
    month = m; day = d; year = y;
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

bool Date::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

bool Date::isLeapYear() const {
    return isLeapYear(year);
}

int Date::lastDay(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}

int Date::lastDay() const {
    return lastDay(month, year);
}

std::string Date::toString1() const {
    std::ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

std::string Date::toString2() const {
    std::ostringstream oss;
    oss << getMonthName(month) << " " << day << ", " << year;
    return oss.str();
}

std::string Date::toString3() const {
    std::ostringstream oss;
    oss << day << " " << getMonthName(month) << " " << year;
    return oss.str();
}

// Operator overloads
Date& Date::operator++() {
    if (day == lastDay()) {
        day = 1;
        if (month == 12) {
            month = 1;
            ++year;
        } else {
            ++month;
        }
    } else {
        ++day;
    }
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() {
    if (day == 1) {
        if (month == 1) {
            month = 12;
            --year;
        } else {
            --month;
        }
        day = lastDay();
    } else {
        --day;
    }
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

int Date::operator-(const Date& other) const {
    // Simple implementation - counts days between dates
    int days = 0;
    Date temp = other;
    while (temp.year < year || temp.month < month || temp.day < day) {
        ++temp;
        ++days;
    }
    return days;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString2();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    std::cout << "Enter date (MM/DD/YYYY): ";
    int m, d, y;
    char slash;
    is >> m >> slash >> d >> slash >> y;
    date.setDate(m, d, y);
    return is;
}
