/**
 * @file Date.h
 * @brief Defines the Date class for handling dates.
 * 
 * The date class allows dates to be set, and also has getters to retrieve the date.
 * The date class makes it possible to test certain functionalities, like monthly interest, yearly interest, 
 and deducing the creditcard balance with the checking account balance.
 */

#pragma once
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

 /**
  * @class Date
  * @brief Class representing a date.
  *  * The date class allows dates to be set, and also has getters to retrieve the date.
 * The date class makes it possible to test certain functionalities, like monthly interest, yearly interest, 
 and deducing the creditcard balance with the checking account balance.
  */
class Date {
private:
    int day;    /**< The day of the date. */
    int month;  /**< The month of the date. */
    int year;   /**< The year of the date. */

public:
    /**
     * @brief Default constructor.
     * Initializes the date to the current date.
     */
    Date();

    /**
     * @brief Constructor.
     * @param day The day of the date.
     * @param month The month of the date.
     * @param year The year of the date.
     */
    Date(int day, int month, int year);

    /**
     * @brief Sets the date from a string.
     * @param date_str A string in the format "DD/MM/YYYY".
     */
    void set_date(const std::string& date_str);

    /**
     * @brief Gets the day of the date.
     * @return The day of the date.
     */
    int get_day() const;

    /**
     * @brief Gets the month of the date.
     * @return The month of the date.
     */
    int get_month() const;

    /**
     * @brief Gets the year of the date.
     * @return The year of the date.
     */
    int get_year() const;
};

#endif // DATE_H
