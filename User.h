/**
 * @file User.h
 * @brief Contains the declaration of the User class.
 * This class constructs a new user object, with a username, password and role.
 * This lets the class create users of different roles, like customer, cashier and director.
 * It also has a get_role function, which is used in the bank class, so that each role has their own options inside the banking sytem.
 */

#pragma once
#ifndef USER_H
#define USER_H

#include <string>

 /**
  * @brief A class representing a user.
 * This class constructs a new user object, with a username, password and role.
 * This lets the class create users of different roles, like customer, cashier and director.
 * It also has a get_role function, which is used in the bank class, so that each role has their own options inside the banking sytem.
  */
class User {
public:
    /**
     * @brief Constructs a new User object.
     * @param username The username of the user.
     * @param password The password of the user.
     * @param role The role of the user.
     */
    User(std::string username, std::string password, std::string role);

    /**
     * @brief Gets the username of the user.
     * @return The username of the user.
     */
    std::string get_username() const;

    /**
     * @brief Gets the password of the user.
     * @return The password of the user.
     */
    std::string get_password() const;

    /**
     * @brief Gets the role of the user.
     * @return The role of the user.
     */
    std::string get_role() const;

private:
    std::string username; /**< The username of the user. */
    std::string password; /**< The password of the user. */
    std::string role; /**< The role of the user. */
};

#endif // USER_H
