/**
 * @file WaterBill.h
 * @brief Header file for WaterBill class, a derived class of Bill
 * @details This class is a subclass of the Bill class and inherits its properties and methods.
 */

#pragma once
#ifndef WATERBILL_H
#define WATERBILL_H

#include "Bills.h"

 /**
  * @class WaterBill
  * @brief A derived class of Bill representing a water bill
  * @details This class is a subclass of the Bill class and inherits its properties and methods.
  */
class WaterBill : public Bill {
public:
    /**
     * @brief Constructor for WaterBill class
     * @param amt The amount due for the water bill
     */
    WaterBill(double amt);

    /**
     * @brief Get the type of bill
     * @return A string representing the type of bill (water)
     */
    std::string get_type() const override;
};

#endif // WATERBILL_H