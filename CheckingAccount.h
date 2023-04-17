/**
 * @file CheckingAccount.h
 * @brief Header file for the CheckingAccount class, which represents a checking account in a bank.
 * 
 * This class inherits from the Account class and provides an implementation of the
  * get_account_type() method to return "checking".
 */

#pragma once
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "account.h"

 /**
  * @class CheckingAccount
  * @brief A class that represents a checking account in a bank.
  *
  * This class inherits from the Account class and provides an implementation of the
  * get_account_type() method to return "checking".
  */
class CheckingAccount : public Account {
public:
    /**
     * @brief Default constructor for the CheckingAccount class.
     */
    CheckingAccount();

    /**
     * @brief Parameterized constructor for the CheckingAccount class.
     *
     * @param num The account number for the checking account.
     * @param bal The balance for the checking account.
     */
    CheckingAccount(int num, double bal);

    /**
     * @brief Override of the Account class's get_account_type() method.
     *
     * This method returns the string "checking" to indicate that this is a checking account.
     *
     * @return The string "checking".
     */
    virtual std::string get_account_type() const override;
};

#endif // CHECKINGACCOUNT_H
