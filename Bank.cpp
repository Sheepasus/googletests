#include "Bank.h"
using namespace std;


Bank::Bank() {// create some initial accounts
    checking_accounts.push_back(make_shared<CheckingAccount>(123, 1000.0));
    checking_accounts.push_back(make_shared<CheckingAccount>(444, 200.0));
    savings_accounts.push_back(make_shared<SavingsAccount>(456, 5000.0));
    checking_accounts.push_back(make_shared<CheckingAccount>(789, 2500.0));
    savings_accounts.push_back(make_shared<SavingsAccount>(321, 4000.0));  // added savings account for alice

    // initialize bills for henk and alice accounts
    user_bills["alice"].push_back(make_shared<WaterBill>(75.0)); // bill for alice
    user_bills["alice"].push_back(make_shared<ElectricityBill>(100.0)); // bill for alice
    user_bills["henk"].push_back(make_shared<WaterBill>(50.0)); // bill for henk
    user_bills["henk"].push_back(make_shared<ElectricityBill>(80.0)); // bill for henk

    // create some initial users
    users.push_back(User("alice", "pass1", "customer"));
    users.push_back(User("henk", "zomer", "customer"));
    users.push_back(User("bob", "pass2", "cashier"));
    users.push_back(User("charlie", "pass3", "director"));

    // add creditcard accounts for alice and henk
    shared_ptr<CheckingAccount> alice_linked_acc = nullptr;
    shared_ptr<CheckingAccount> henk_linked_acc = nullptr;
    for (auto& acc : checking_accounts) {
        if (acc->get_account_num() == 123) {
            alice_linked_acc = acc;
        }
        else if (acc->get_account_num() == 789) {
            henk_linked_acc = acc;
        }
    }

    creditcard_accounts.push_back(CreditCard(8888, -500.0, alice_linked_acc));
    creditcard_accounts.push_back(CreditCard(9999, -1000.0, henk_linked_acc));

    // populate the user_accounts map with the accounts of each user
    for (auto& user : users) {
        if (user.get_username() == "alice") {  // add alice's accounts
            user_accounts[user.get_username()].push_back(checking_accounts[0]);
            user_accounts[user.get_username()].push_back(savings_accounts[0]);
            user_accounts[user.get_username()].push_back(make_shared<CreditCard>(creditcard_accounts[0]));
        }
        else if (user.get_username() == "henk") {  // add henk's accounts
            user_accounts[user.get_username()].push_back(checking_accounts[1]);
            user_accounts[user.get_username()].push_back(checking_accounts[2]);
            user_accounts[user.get_username()].push_back(savings_accounts[1]);
            user_accounts[user.get_username()].push_back(make_shared<CreditCard>(creditcard_accounts[1]));
        }
        else {
            for (auto& acc : checking_accounts) {
                user_accounts[user.get_username()].push_back(make_shared<CheckingAccount>(*acc));
            }
            for (auto& acc : savings_accounts) {
                user_accounts[user.get_username()].push_back(make_shared<SavingsAccount>(*acc));
            }
        }
    }
}

// function to find user by username and password
User* Bank::find_user(string username, string password) {
    for (auto& user : users) {
        if (user.get_username() == username && user.get_password() == password) {
            return &user;
        }
    }
    return nullptr;
}

bool Bank::login(string username, string password) {
    User* user = find_user(username, password);
    if (user != nullptr) {
        current_user = user;
        current_user_role = user->get_role();
        return true;
    }
    else {
        return false;
    }
}

void Bank::logout() {
    current_user = nullptr;
    current_user_role = "";
}

bool Bank::is_logged_in() const {
    return current_user != nullptr;
}






// function to deposit money into an account
void Bank::deposit(int account_num, double amount) {
    for (auto acc : user_accounts.at(current_user->get_username())) {
        if (acc->get_account_type() == "Creditcard Account") {
            acc->deposit(amount - 0.5);
            cout << "deposit of " << amount << " made to credit card account " << account_num << endl;
            break;

        }
        else if (acc->get_account_num() == account_num) {
            acc->deposit(amount);
            if (acc->get_account_type() == "Checking Account") {
                cout << "deposit of " << amount << " made to checking account " << account_num << endl;
            }
            if (acc->get_account_type() == "Savings Account") {
                cout << "deposit of " << amount << " made to savings account " << account_num << endl;
            }
        }
    }
}

// function to withdraw money from an account
bool Bank::withdraw(int account_num, double amount) {
    for (auto acc : user_accounts.at(current_user->get_username())) {
        if (acc->get_account_type() == "Creditcard Account") {
            acc->withdraw(amount + 0.5);
            cout << "withdrawal of " << amount << " from credit card account " << account_num << endl;
            return true;

        }

        else if (acc->get_account_num() == account_num) {
            acc->withdraw(amount);
            if (acc->get_account_type() == "Checking Account") {
                cout << "withdrawal of " << amount << " is withdrawn from checking account " << account_num << endl;
            }
            if (acc->get_account_type() == "Savings Account") {
                cout << "withdrawal of " << amount << " is withdrawn from savings account " << account_num << endl;
            }
            return true;
        }
    }
    return false;
}



void Bank::pay_bill(shared_ptr<Bill> bill, int account_num) {
    // find the account with the given account number
    shared_ptr<Account> account = nullptr;
    for (auto& acc : user_accounts[current_user->get_username()]) {
        if (acc->get_account_num() == account_num) {
            account = acc;
            break;
        }
    }
    if (account == nullptr) {
        cout << "Account not found." << endl;
        return;
    }

    if (account->get_account_type() == "Creditcard Account") {
        bill->mark_paid();
        account->withdraw(-(bill->get_amount() + 0.5));
    }
    else {


        // check if there are sufficient funds in the account
        if (bill->get_amount() > account->get_balance()) {
            cout << "Insufficient funds." << endl;
            return;
        }


        // mark the bill as paid and deduct the amount from the account
        bill->mark_paid();
        account->withdraw(bill->get_amount());
    }
}

vector<shared_ptr<Bill>> Bank::get_user_bills(string username) {
    return user_bills[username];
}

void Bank::add_interest(Date current_date) {
    if (current_date.get_month() == 12 && current_date.get_day() == 31) {
        for (shared_ptr<CheckingAccount> checking_account : checking_accounts) {
            double interest_rate = 0.01;
            double interest = checking_account->get_balance() * interest_rate;
            checking_account->deposit(interest); // double interest if it's 31st December
        }
        for (shared_ptr<SavingsAccount> savings_account : savings_accounts) {
            double interest_rate = 0.05;
            double interest = savings_account->get_balance() * interest_rate;
            savings_account->deposit(interest); // double interest if it's 31st December
        }
        cout << "Interest added to accounts" << endl;
    }
    else {
        cout << "No interest added today." << endl;
    }
}

void Bank::negative_monthly_interest(Date current_date) {
    if (current_date.get_day() == 28) {
        for (shared_ptr<CheckingAccount> checking_account : checking_accounts) {
            if (checking_account->get_balance() < 0) {
                double interest_rate = 0.03;
                double interest = checking_account->get_balance() * interest_rate;
                checking_account->withdraw(interest); // Negative interest added to checking account, due to balance being negative
                cout << "Negative interest added to checking accounts" << endl;
            }

        }

    }

}


void Bank::deduce_creditcard_balance(const Date& current_date) {
    if (current_date.get_day() >= 28) {
        for (CreditCard& creditcard_account : creditcard_accounts) {
            auto linked_acc = creditcard_account.get_linked_account();
            double cc_balance = creditcard_account.get_balance();
            if (cc_balance < 0) {
                linked_acc->withdraw((-1 * cc_balance));
            }
            else { linked_acc->deposit((cc_balance)); }

            if (cc_balance <= 0) {
                creditcard_account.deposit(-1 * cc_balance);

            }
            else {
                creditcard_account.withdraw(cc_balance);

            }
            cout << "creditcard balance is deducted from checking account." << endl;
        }
    }
}

User* Bank::get_user(const string& username) {
    for (auto& user : users) {
        if (user.get_username() == username) {
            return &user;
        }
    }
    return nullptr;
}

vector<shared_ptr<Account>> Bank::get_user_accounts() const {
    vector<shared_ptr<Account>> accounts;
    if (!is_logged_in()) {
        return accounts;
    }

    // retrieve the accounts associated with the current user
    auto user_account_ptrs = user_accounts.at(current_user->get_username());
    for (auto account_ptr : user_account_ptrs) {
        accounts.push_back(account_ptr);
    }

    return accounts;
}

bool Bank::add_account(const string& username) {
    User* user = get_user(username);
    if (user == nullptr) {
        cout << "Error: User not found." << endl;
        return false;
    }

    int choice;
    bool added = false;
    do {
        cout << endl << "Select account type to add: " << endl;
        cout << "1. Checking Account" << endl;
        cout << "2. Savings Account" << endl;
        cout << "3. Credit Card Account" << endl;
        cout << "4. Cancel" << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            int account_num;
            double balance;
            cout << "Enter account number: ";
            cin >> account_num;
            cout << "Enter balance: ";
            cin >> balance;
            auto acc = make_shared<CheckingAccount>(account_num, balance);
            checking_accounts.push_back(acc);
            auto acc_ptr = std::make_shared<CheckingAccount>(*acc);
            user_accounts[username].push_back(acc_ptr);

            cout << "Checking account added successfully." << endl;
            added = true;
            break;
        }
        case 2: {
            int account_num;
            double balance;
            cout << "Enter account number: ";
            cin >> account_num;
            cout << "Enter balance: ";
            cin >> balance;
            auto acc = make_shared<SavingsAccount>(account_num, balance);
            savings_accounts.push_back(acc);
            auto acc_ptr = std::make_shared<SavingsAccount>(*acc);
            user_accounts[username].push_back(acc_ptr);
            cout << "Savings account added successfully." << endl;
            added = true;
            break;
        }
        case 3: {
            int account_num;
            double balance;
            int linked_account_num;
            cout << "Enter account number: ";
            cin >> account_num;
            cout << "Enter balance: ";
            cin >> balance;
            cout << "Enter checking account number to link creditcard account to: ";
            cin >> linked_account_num;
            CheckingAccount* user_linked_acc = nullptr;
            for (auto& acc : checking_accounts) {
                if (auto linked_acc = dynamic_cast<CheckingAccount*>(acc.get())) {
                    if (linked_acc->get_account_num() == linked_account_num) {
                        user_linked_acc = linked_acc;
                        break;
                    }
                }
            }


            if (user_linked_acc == nullptr) {
                cout << "Error: Linked account not found." << endl;
                break;
            }
            auto acc = make_shared<CreditCard>(account_num, balance, shared_ptr<Account>(user_linked_acc));
            creditcard_accounts.push_back(*acc);
            auto acc_ptr = std::make_shared<CreditCard>(*acc);
            user_accounts[username].push_back(acc_ptr);
            cout << "Credit card account added successfully." << endl;
            added = true;
            break;

            added = true;
            break;
        }
        case 4:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return added;
}








vector<shared_ptr<Account>> Bank::get_user_accounts_by_username(const string& username) const {
    vector<shared_ptr<Account>> accounts;
    auto it = user_accounts.find(username);
    if (it != user_accounts.end()) {
        for (auto account : it->second) {
            accounts.push_back(account);
        }
    }
    return accounts;
}

void Bank::add_user() {
    string username, password;
    cout << "Enter the new user's username: ";
    cin >> username;
    cout << "Enter the new user's password: ";
    cin >> password;

    // Check if the user already exists
    for (auto& user : users) {
        if (user.get_username() == username) {
            cout << "Error: User already exists." << endl;
            return;
        }
    }

    // Create a new cashier and add it to the system

    users.push_back(User(username, password, "cashier"));
    cout << "Cashier hired." << endl;


}

void Bank::delete_user() {
    string username;
    cout << "Enter the username of the user you want to delete: ";
    cin >> username;

    // Find the user in the system
    auto it = users.begin();
    while (it != users.end()) {
        if (it->get_username() == username) {
            if (it->get_role() == "cashier") {
                // Remove the user from the system
                it = users.erase(it);
                cout << "Cashier is fired." << endl;
                return;
            }
            else {
                cout << "you can only fire cashiers." << endl;
                return;
            }
        }
        else {
            ++it;
        }
    }

    // User not found
    cout << "Error: User not found." << endl;
}



