


//Libraries
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>

//Headers
#include "Bank.h"

using namespace std;


int main() {
    Bank bank;
    string username, password;
    Date date(1, 1, 2022); // creates a date object with values 1, 1, 2022

    while (true) {
        cout << "Welcome to the bank. Please login to continue." << endl;
        cout << "1. Login" << endl;
        cout << "2. set date" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter choice (1-3: ";
        int choice;
        cin >> choice;
        if (choice == 3) {
            break;
        }
        else if (choice == 1) {
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            if (bank.login(username, password)) {
                cout << "Login successful!" << endl;

                bank.add_interest(date);
                bank.deduce_creditcard_balance(date);
                bank.negative_monthly_interest(date);
                
            }
            else {
                cout << "Invalid username or password. Please try again." << endl;
                continue;
            }
        }

        else if (choice == 2) {
            cout << "date should be in format dd-mm-yyyy" << endl;
            cout << "set date: ";
            string input_date;
            cin >> input_date;
            date.set_date(input_date);
            continue;
            
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }


        User* user = bank.get_user(username);
        if (user->get_role() == "customer") {
            // The user is a customer
            while (true) {
                cout << endl << "What would you like to do?" << endl;
                cout << "1. View bank accounts" << endl;
                cout << "2. View bills" << endl;
                cout << "3. Log out" << endl;
                cout << "Enter choice (1-3): ";
                cin >> choice;
                if (choice == 3) {
                    bank.logout();
                    break;
                }
                else if (choice == 2) {
                    cout << "Your bills:" << endl;
                    for (auto bill : bank.get_user_bills(username)) {
                        cout << bill->get_type() << " - $" << bill->get_amount() << endl;
                    }

                }
                else if (choice == 1) {
                    vector<shared_ptr<Account>> accounts = bank.get_user_accounts();
                    cout << endl << "Your accounts:" << endl;
                    int i = 1;
                    map<int, shared_ptr<Account>> account_map;
                    for (auto acc : accounts) {
                        cout << i << ". " << acc->get_account_type() << " (" << acc->get_account_num() << "): " << acc->get_balance() << endl;
                        account_map[i] = acc;
                        i++;
                    }
                    cout << i << ". Go back" << endl;
                    cout << "Select an account (1-" << i << "): ";
                    int account_choice;
                    cin >> account_choice;
                    if (account_choice == i) {
                        continue;
                    }
                    shared_ptr<Account> account = account_map[account_choice];
                    cout << "Selected account: " << account->get_account_type() << " (" << account->get_account_num() << ")" << endl;
                    while (true) {
                        cout << endl << "What would you like to do?" << endl;
                        cout << "1. Deposit" << endl;
                        cout << "2. Withdraw" << endl;
                        cout << "3. Pay bill" << endl;
                        cout << "4. Go back to main menu" << endl;
                        cout << "Enter choice (1-5): ";
                        cin >> choice;
                        if (choice == 1) {
                            cout << "Enter amount to deposit: ";
                            double amount;
                            cin >> amount;
                            bank.deposit(account->get_account_num(), amount);
                            cout << "Deposit successful. New balance: " << account->get_balance() << endl;
                        }
                        else if (choice == 2) {
                            cout << "Enter amount to withdraw: ";
                            double amount;
                            cin >> amount;
                            if (bank.withdraw(account->get_account_num(), amount)) {
                                cout << "Withdrawal successful. New balance: " << account->get_balance() << endl;
                            }
                            else {
                                cout << "Insufficient funds. Withdrawal unsuccessful." << endl;
                            }
                        }
                        else if (choice == 3) {
                            cout << "Your bills:" << endl;
                            vector<shared_ptr<Bill>> user_bills = bank.get_user_bills(username);
                            for (int i = 0; i < user_bills.size(); i++) {
                                cout << i + 1 << ". " << user_bills[i]->get_type() << " - $" << user_bills[i]->get_amount() << endl;
                            }
                            cout << "Select bill: ";
                            int bill_index;
                            cin >> bill_index;
                            if (bill_index <= 0 || bill_index > user_bills.size()) {
                                cout << "Invalid selection." << endl;
                                return 0;
                            }
                            shared_ptr<Bill> bill = user_bills[bill_index - 1];
                            bank.pay_bill(bill, account->get_account_num());
                            cout << "Bill paid." << endl;
                        }

                        else if (choice == 4) {
                            break;
                        }
                        else {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                }

            }
        }
        else if (user->get_role() == "cashier") {
            while (true) {
                cout << endl << "What would you like to do?" << endl;
                cout << "1. View all accounts of a user" << endl;
                cout << "2. Open a new account for a user" << endl;
                cout << "3. Log out" << endl;
                cout << "Enter choice (1-3): ";
                int choice;
                cin >> choice;
                if (choice == 3) {
                    bank.logout();
                    break;
                }
                else if (choice == 1) {
                    cout << "Enter username: ";
                    string username;
                    cin >> username;
                    vector<shared_ptr<Account>> accounts = bank.get_user_accounts_by_username(username);
                    if (accounts.empty()) {
                        cout << "No accounts found for user " << username << endl;
                    }
                    else {
                        cout << endl << "Accounts for user " << username << ":" << endl;
                        for (auto acc : accounts) {
                            cout << acc->get_account_type() << " (" << acc->get_account_num() << "): " << acc->get_balance() << endl;
                        }
                    }

                }

                else if (choice == 2) {
                    cout << "Enter username: ";
                    string username;
                    cin >> username; 
                    if (bank.add_account(username)) {
                            cout << "Account successfully opened for user " << username << endl;   
                            
                        }
                    else {
                            cout << "Failed to open account for user " << username << endl;
                        }
                    }
                }

            
        }


        else if (user->get_role() == "director") {
            // The user is a director
            cout << "Welcome Director " << user->get_username() << endl;
            cout << "Please choose an option:" << endl;
            cout << "1. Create new cashier account" << endl;
            cout << "2. Delete cashier account" << endl;
            cout << "3. Request total balance" << endl;
            cout << "4. Logout" << endl;

            int choice;
            do {
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                

                    // Hire new cashier
                  
                    bank.add_user();
                    break;
                }
                case 2: {
                    // fire cashier
                    bank.delete_user();
                    break;
                }
                case 3: {
                    // Request total balance
                    double total_balance = 0;
                    
                    for (auto& acc : bank.get_user_accounts()) {
                        total_balance += acc->get_balance();
                    }
                    cout << "Total balance in the bank: $" << total_balance << endl;
                    break;
                }
                case 4: {
                    // Logout
                    cout << "Logging out." << endl;
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }

            } while (choice != 4);

        }


        
    }
    return 0;
}
