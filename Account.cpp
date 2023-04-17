/**
 * @file Account.cpp
 * Implementation file for the Account class.
 */

#include "Account.h"

 /**
  * Default constructor for the Account class.
  */
Account::Account() {}

/**
 * Constructor for the Account class that sets the account number and balance.
 * @param num The account number.
 * @param bal The account balance.
 */
Account::Account(int num, double bal) : account_num(num), balance(bal) {}

/**
 * Virtual function that returns the type of the account as a string.
 * This function is overridden in subclasses to return the specific type of account.
 * @return A string representing the type of account.
 */
std::string Account::get_account_type() const {
    return "undefined_account";
}

/**
 * Destructor for the Account class.
 */
Account::~Account() {}

/**
 * Getter method for the account number.
 * @return The account number.
 */
int Account::get_account_num() const {
    return account_num;
}

/**
 * Getter method for the account balance.
 * @return The account balance.
 */
double Account::get_balance() const {
    return balance;
}

/**
 * Method that adds the specified amount to the account balance.
 * @param new_balance The amount to deposit.
 */
void Account::deposit(double new_balance) {
    balance += new_balance;
}

/**
 * Method that subtracts the specified amount from the account balance.
 * @param new_balance The amount to withdraw.
 */
void Account::withdraw(double new_balance) {
    balance -= new_balance;
}
