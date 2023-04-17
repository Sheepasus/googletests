/**
 * @file CreditCard.h
 * @brief Header file for the CreditCard class
 * The CreditCard class is derived from the Account class and contains a shared pointer to a linked account to which
payments are applied. The class provides methods to get the account type and the linked account, as well as a
constructor and virtual destructor.
 */

#pragma once
#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Account.h"
#include <memory>

 /**
  * @class CreditCard
  * @brief A class representing a credit card account
  * The CreditCard class is derived from the Account class and contains a shared pointer to a linked account to which
  * payments are applied. The class provides methods to get the account type and the linked account, as well as a
  * constructor and virtual destructor.
  */
class CreditCard : public Account {
private:
    std::shared_ptr<Account> linked_account; ///< The linked account to which payments are applied

public:
    /**
     * @brief Constructor for a CreditCard object
     * @param account_num The account number of the credit card account
     * @param bal The balance of the credit card account
     * @param linked_account A shared pointer to the linked account to which payments are applied
     */
    CreditCard(int account_num, double bal, std::shared_ptr<Account> linked_account);

    /**
     * @brief Returns the type of the account
     * @return A string representing the account type, in this case "Credit Card"
     */
    std::string get_account_type() const override;

    /**
     * @brief Returns a shared pointer to the linked account
     * @return A shared pointer to the linked account
     */
    std::shared_ptr<Account> get_linked_account() const;

    /**
     * @brief Virtual destructor for a CreditCard object
     */
    virtual ~CreditCard();
};

#endif // CREDITCARD_H
