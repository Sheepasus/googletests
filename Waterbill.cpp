#include "Waterbill.h"

WaterBill::WaterBill(double amt) : Bill(amt) {}

std::string WaterBill::get_type() const {
    return "Water Bill";
}
