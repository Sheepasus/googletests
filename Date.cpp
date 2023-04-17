#include "date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::set_date(const std::string& date_str) {
    // Extract day, month, and year from the date string
    int day = std::stoi(date_str.substr(0, 2));
    int month = std::stoi(date_str.substr(3, 2));
    int year = std::stoi(date_str.substr(6, 4));

    // Set the date
    this->day = day;
    this->month = month;
    this->year = year;

    std::cout << "date: " << day << "-" << month << "-" << year << std::endl;
}

int Date::get_day() const {
    return day;
}

int Date::get_month() const {
    return month;
}

int Date::get_year() const {
    return year;
}
