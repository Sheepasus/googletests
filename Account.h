/**
 * @file Account.h
 * @brief Header file for the Account class
 *
 * This file contains the declaration of the Account class. The Account class represents a
 * bank account with an account number and a balance. It provides methods to deposit and withdraw
 * money from the account.
 */

#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

 /**
  * @brief A class that represents a bank account
  * 
  * This file contains the declaration of the Account class. The Account class represents a
  * bank account with an account number and a balance. It provides methods to deposit and withdraw
  * money from the account.
  */
class Account {
public:
    /**
     * @brief Default constructor for Account class
     *
     * The default constructor initializes the account number to 0 and the balance to 0.0.
     */
    Account();

    /**
     * @brief Constructor for Account class
     *
     * @param num the account number for the account
     * @param bal the initial balance for the account
     */
    Account(int num, double bal);

    /**
     * @brief Virtual destructor for Account class
     *
     * The destructor is virtual to ensure that derived classes can be destroyed properly.
     */
    virtual ~Account();

    /**
     * @brief Virtual method to get the account type
     *
     * This method returns a string indicating the type of the account.
     *
     * @return a string representing the account type
     */
    virtual std::string get_account_type() const;

    /**
     * @brief Getter for the account number
     *
     * @return the account number
     */
    int get_account_num() const;

    /**
     * @brief Getter for the account balance
     *
     * @return the account balance
     */
    double get_balance() const;

    /**
     * @brief Method to deposit money into the account
     *
     * @param new_balance the new balance after the deposit
     */
    void deposit(double new_balance);

    /**
     * @brief Method to withdraw money from the account
     *
     * @param new_balance the new balance after the withdrawal
     */
    void withdraw(double new_balance);

private:
    int account_num; /**< the account number */
    double balance; /**< the account balance */
};

#endif // ACCOUNT_H
