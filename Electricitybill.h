/**
 * @file ElectricityBill.h
 * @brief Header file for the ElectricityBill class.
 * @details This class is a subclass of the Bill class and inherits its properties and methods.
 */

#pragma once
#ifndef ELECTRICITYBILL_H
#define ELECTRICITYBILL_H

#include "Bills.h"

 /**
  * @brief The ElectricityBill class represents an electricity bill that is owed.
  * @details This class is a subclass of the Bill class and inherits its properties and methods.
  */
class ElectricityBill : public Bill {
public:
    /**
     * @brief Constructs an ElectricityBill object with the given amount owed.
     * @param amt The amount of money owed for the electricity bill.
     */
    ElectricityBill(double amt);

    /**
     * @brief Returns the type of the bill as a string.
     * @return A string representing the type of bill (in this case, "Electricity").
     */
    std::string get_type() const override;
};

#endif // ELECTRICITYBILL_H
