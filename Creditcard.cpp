#include "CreditCard.h"

CreditCard::CreditCard(int account_num, double bal, std::shared_ptr<Account> linked_account)
    : Account(account_num, bal), linked_account(linked_account) {}

std::string CreditCard::get_account_type() const {
    return "Creditcard Account";
}

std::shared_ptr<Account> CreditCard::get_linked_account() const {
    return linked_account;
}

CreditCard::~CreditCard() {}
