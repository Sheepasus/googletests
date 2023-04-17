/**
*@file Bills.h
*@brief Defines the Bill class and its methods.
*
*The Bill class provides a base class for representing bills. It allows derived classes to define their own
*types of bills and implements basic functionality for tracking the amount and payment status of bills.
*/
#pragma once
#ifndef BILL_H
#define BILL_H
#include <string>
#include <iostream>

/**

@class Bill

@brief Abstract class for defining bill objects.

The Bill class provides a base class for representing bills. It allows derived classes to define their own

types of bills and implements basic functionality for tracking the amount and payment status of bills.
*/
class Bill {
public:

/**
@brief Constructs a new Bill object with the given amount.
@param amt The amount of the bill.
*/
Bill(double amt);

/**
@brief Virtual destructor for the Bill class.
*/
virtual ~Bill();
/**

@brief Pure virtual function to get the type of the bill.
@return The type of the bill as a string.
*/
virtual std::string get_type() const = 0;
/**

@brief Gets the amount of the bill.
@return The amount of the bill.
*/
double get_amount() const;
/**

@brief Checks if the bill has been paid.
@return True if the bill has been paid, false otherwise.
*/
bool is_paid() const;
/**

@brief Marks the bill as paid.
*/
void mark_paid();
private:
	double amount; /** < The amount of the bill.*/
		bool paid; /** < The payment status of the bill.True if the bill has been paid, false otherwise.*/
};

#endif // BILL_H