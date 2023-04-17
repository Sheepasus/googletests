#include "user.h"

User::User(std::string username, std::string password, std::string role)
    : username(username), password(password), role(role) {}

std::string User::get_username() const {
    return username;
}

std::string User::get_password() const {
    return password;
}

std::string User::get_role() const {
    return role;
}
