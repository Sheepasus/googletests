#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account() {}

SavingsAccount::SavingsAccount(int num, double bal) : Account(num, bal) {}

std::string SavingsAccount::get_account_type() const {
    return "Savings Account";
}
