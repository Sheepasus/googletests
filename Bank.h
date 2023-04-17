
/**

@mainpage Bank Class Example
@section intro_sec Introduction
This code example demonstrates the usage of the Bank class. The Bank class is responsible for managing accounts and transactions for a bank. It allows customers to view their accounts, deposit and withdraw money, and pay bills. Whereas it lets cashiers view users accounts, and create and delete new accounts for users. The bank system also lets the director check the total balance of all bank accounts, and hire and fire cashiers.
@section usage_sec Usage
To use the Bank class, first create an instance of it:
@code
Bank bank;
@endcode
Once you have created an instance of the Bank class, you can perform various operations such as depositing and withdrawing money from accounts. The following example code demonstrates how to use the deposit and withdraw functions:
@code
bank.login("alice", "pass1");
bank.deposit(123, 100.0); // deposit to alice's checking account
bank.withdraw(123, 50.0); // withdraw from alice's checking account
bank.logout();
@endcode
In the above example, the code logs into alice's account using the login function, deposits 100.0 to her checking account using the deposit function, withdraws 50.0 from her checking account using the withdraw function, and logs out using the logout function.
*/



/**
 * @file Bank.h
 * @brief Header file for the Bank class
 *
 * The Bank class is responsible for managing user accounts, handling financial transactions, and generating bills.
 * It provides functions for users to login and logout of their account, deposit and withdraw money into or from their accounts, pay bills, add and remove accounts, and manage interest rates.
 * The Bank class stores information about user accounts, bills, and credit cards using structures like vectors and maps.
 * It also makes use of other classes like Account, CheckingAccount, SavingsAccount, CreditCard, User, Bills, Waterbill, Electricitybill, and Date to provide its functionalities.
 * The Bank class maintains a pointer to the currently logged-in user, and stores the role of the user as either "customer", "cashier" or "director".
 * Additionally, the Bank class has various functions for retrieving information about user accounts and bills.
 * To summarize it, the Bank class provides all functionalities for the consumer, cashier and director.
 */

#pragma once
#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>

#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Creditcard.h"
#include "User.h"
#include "Bills.h"
#include "Waterbill.h"
#include "Electricitybill.h"
#include "Date.h"

/**
  * @brief A class that represents the banking system
  * 
  * The Bank class is responsible for managing user accounts, handling financial transactions, and generating bills.
 * It provides functions for users to login and logout of their account, deposit and withdraw money into or from their accounts, pay bills, add and remove accounts, and manage interest rates.
 * The Bank class stores information about user accounts, bills, and credit cards using structures like vectors and maps.
 * It also makes use of other classes like Account, CheckingAccount, SavingsAccount, CreditCard, User, Bills, Waterbill, Electricitybill, and Date to provide its functionalities.
 * The Bank class maintains a pointer to the currently logged-in user, and stores the role of the user as either "customer", "cashier" or "director".
 * Additionally, the Bank class has various functions for retrieving information about user accounts and bills.
 * To summarize it, the Bank class provides all functionalities for the consumer, cashier and director.
  */
class Bank {
private:
    std::vector<std::shared_ptr<CheckingAccount>> checking_accounts; /**< Vector of shared pointers to CheckingAccount objects */
    std::vector<std::shared_ptr<SavingsAccount>> savings_accounts; /**< Vector of shared pointers to SavingsAccount objects */
    std::vector<CreditCard> creditcard_accounts; /**< Vector of CreditCard objects */
    std::vector<User> users; /**< Vector of User objects */
    User* current_user; /**< Pointer to the current User object */
    std::string current_user_role; /**< String representing the current user's role */
    std::unordered_map<std::string, std::vector<std::shared_ptr<Account>>> user_accounts; /**< Unordered map representing the user accounts */
    std::vector<std::shared_ptr<Bill>> open_bills; /**< Vector of shared pointers to Bill objects representing open bills */
    std::unordered_map<std::string, std::vector<std::shared_ptr<Bill>>> user_bills; /**< Unordered map representing the user bills */

public:
    /**
     * @brief Default constructor
     */
    Bank();

    /**
     * @brief Logs in a user with a given username and password
     * @param username The username to log in with
     * @param password The password to log in with
     * @return True if the login was successful, false otherwise
     */
    bool login(std::string username, std::string password);

    /**
     * @brief Logs out the current user
     */
    void logout();

    /**
     * @brief Checks whether a user is logged in or not
     * @return True if a user is logged in, false otherwise
     */
    bool is_logged_in() const;

    /**
     * @brief Finds a user with a given username and password
     * @param username The username to find
     * @param password The password to find
     * @return A pointer to the User object if found, nullptr otherwise
     */
    User* find_user(std::string username, std::string password);

    /**
     * @brief Deposits a given amount into an account with a given account number
     * @param account_num The account number of the account to deposit into
     * @param amount The amount to deposit
     */
    void deposit(int account_num, double amount);

    /**
     * @brief Withdraws a given amount from an account with a given account number
     * @param account_num The account number of the account to withdraw from
     * @param amount The amount to withdraw
     * @return True if the withdrawal was successful, false otherwise
     */
    bool withdraw(int account_num, double amount);

    /**
     * @brief Gets a vector of shared pointers to Account objects belonging to the current user
     * @return A vector of shared pointers to Account objects belonging to the current user
     */
  
    std::vector<std::shared_ptr<Account>> get_user_accounts() const;

    /**
     * @brief Returns a vector of shared pointers to all the bills of the specified user
     *
     * @param username A string representing the username of the user whose bills are to be returned
     * @return std::vector<std::shared_ptr<Bill>> A vector of shared pointers to all the bills of the specified user
     */
    std::vector<std::shared_ptr<Bill>> get_user_bills(std::string username);

    /**
     * @brief Pays the specified bill from the specified account
     *
     * @param bill A shared pointer to the bill to be paid
     * @param account_num An integer representing the account number from which the bill is to be paid
     */
    void pay_bill(std::shared_ptr<Bill> bill, int account_num);

    /**
     * @brief Adds monthly interest to all savings accounts
     *
     * @param current_date A Date object representing the current date
     */
    void add_interest(Date current_date);

    /**
     * @brief Deducts monthly interest from all negative balance accounts
     *
     * @param current_date A Date object representing the current date
     */
    void negative_monthly_interest(Date current_date);

    /**
     * @brief Deducts the credit card balance for the current month
     *
     * @param current_date A Date object representing the current date
     */
    void deduce_creditcard_balance(const Date& current_date);

    /**
     * @brief Returns a pointer to the user with the specified username
     *
     * @param username A string representing the username of the user to be returned
     * @return User* A pointer to the user with the specified username
     */
    User* get_user(const std::string& username);

    /**
     * @brief Adds a new account for the specified user
     *
     * @param username A string representing the username of the user for whom the account is to be added
     * @return true If the account was added successfully
     * @return false If the account was not added successfully
     */
    bool add_account(const std::string& username);

    /**
     * @brief Adds a new user to the bank
     *
     */
    void add_user();

    /**
     * @brief Deletes the specified user from the bank
     *
     */
    void delete_user();

    /**
     * @brief Returns a vector of shared pointers to all the accounts of the specified user
     *
     * @param username A string representing the username of the user whose accounts are to be returned
     * @return std::vector<std::shared_ptr<Account>> A vector of shared pointers to all the accounts of the specified user
     */
    std::vector<std::shared_ptr<Account>> get_user_accounts_by_username(const std::string& username) const;

};

#endif // BANK.H
