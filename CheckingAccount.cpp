#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() : Account() {}

CheckingAccount::CheckingAccount(int num, double bal) : Account(num, bal) {}

std::string CheckingAccount::get_account_type() const {
    return "Checking Account";
}
