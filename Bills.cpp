#include "Bills.h"

Bill::Bill(double amt) : amount(amt), paid(false) {}

Bill::~Bill() {} // define the destructor

double Bill::get_amount() const {
    return amount;
}

bool Bill::is_paid() const {
    return paid;
}

void Bill::mark_paid() {
    paid = true;
}
