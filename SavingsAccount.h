/**
 * @file SavingsAccount.h
 * @brief Header file for the SavingsAccount class.
 * This class inherits from the Account class and provides an implementation of the
 * get_account_type() method to return "savings".
 */

#pragma once
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "account.h"


 /**
  * @class SavingsAccount
  * @brief A subclass of the Account class representing a savings account.
  * * This class inherits from the Account class and provides an implementation of the
 * get_account_type() method to return "savings".
  */
class SavingsAccount : public Account {
public:
    /**
     * @brief Default constructor for SavingsAccount.
     */
    SavingsAccount();

    /**
     * @brief Constructor for SavingsAccount.
     * @param num The account number.
     * @param bal The account balance.
     */
    SavingsAccount(int num, double bal);

    /**
     * @brief Get the account type.
     * @return A string indicating the account type ("Savings").
     */
    virtual std::string get_account_type() const override;
};

#endif // SAVINGS_ACCOUNT_H
