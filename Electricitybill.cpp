#include "Electricitybill.h"

ElectricityBill::ElectricityBill(double amt) : Bill(amt) {}

std::string ElectricityBill::get_type() const {
    return "Electricity Bill";
}
