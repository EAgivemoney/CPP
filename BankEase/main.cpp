#include <iostream>
#include <vector>
#include <memory>
#include "Customer.h"
#include "Staff.h"
#include "Account.h"
#include "Utils.h"

std::vector<std::unique_ptr<Customer>> customers;
std::vector<std::unique_ptr<Staff>> staffMembers;
std::vector<std::unique_ptr<Account>> accounts;

void createCustomer() {
    std::string name;
    int id;
    double initialBalance;

    std::cout << "Enter Customer Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    if (!Utils::isValidName(name)) {
        std::cout << "Invalid name. Please try again.\n";
        return;
    }

    std::cout << "Enter Customer ID: ";
    std::cin >> id;
    if (!Utils::isValidID(id)) {
        std::cout << "Invalid ID. Please try again.\n";
        return;
    }

    std::cout << "Enter Initial Balance: ";
    std::cin >> initialBalance;
    if (!Utils::isValidAmount(initialBalance)) {
        std::cout << "Invalid amount. Please try again.\n";
        return;
    }

    customers.push_back(std::make_unique<Customer>(name, id, initialBalance));
    std::cout << "Customer created successfully!\n";
}

void createStaff() {
    std::string name, role;
    int id;

    std::cout << "Enter Staff Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    if (!Utils::isValidName(name)) {
        std::cout << "Invalid name. Please try again.\n";
        return;
    }

    std::cout << "Enter Staff ID: ";
    std::cin >> id;
    if (!Utils::isValidID(id)) {
        std::cout << "Invalid ID. Please try again.\n";
        return;
    }

    std::cout << "Enter Staff Role: ";
    std::cin.ignore();
    std::getline(std::cin, role);

    staffMembers.push_back(std::make_unique<Staff>(name, id, role));
    std::cout << "Staff created successfully!\n";
}

void createAccount() {
    std::string accountNumber;
    double initialBalance;

    std::cout << "Enter Account Number: ";
    std::cin >> accountNumber;

    std::cout << "Enter Initial Balance: ";
    std::cin >> initialBalance;
    if (!Utils::isValidAmount(initialBalance)) {
        std::cout << "Invalid amount. Please try again.\n";
        return;
    }

    accounts.push_back(std::make_unique<Account>(accountNumber, initialBalance));
    std::cout << "Account created successfully!\n";
}

void depositToAccount() {
    std::string accountNumber;
    double amount;

    std::cout << "Enter Account Number: ";
    std::cin >> accountNumber;

    std::cout << "Enter Deposit Amount: ";
    std::cin >> amount;
    if (!Utils::isValidAmount(amount)) {
        std::cout << "Invalid amount. Please try again.\n";
        return;
    }

    for (auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            account->deposit(amount);
            return;
        }
    }

    std::cout << "Account not found.\n";
}

void withdrawFromAccount() {
    std::string accountNumber;
    double amount;

    std::cout << "Enter Account Number: ";
    std::cin >> accountNumber;

    std::cout << "Enter Withdrawal Amount: ";
    std::cin >> amount;
    if (!Utils::isValidAmount(amount)) {
        std::cout << "Invalid amount. Please try again.\n";
        return;
    }

    for (auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            if (!account->withdraw(amount)) {
                std::cout << "Withdrawal failed.\n";
            }
            return;
        }
    }

    std::cout << "Account not found.\n";
}

void displayAllCustomers() {
    if (customers.empty()) {
        std::cout << "No customers found.\n";
        return;
    }

    for (const auto& customer : customers) {
        customer->displayInfo();
        std::cout << "-------------------\n";
    }
}

void displayAllStaff() {
    if (staffMembers.empty()) {
        std::cout << "No staff members found.\n";
        return;
    }

    for (const auto& staff : staffMembers) {
        staff->displayInfo();
        std::cout << "-------------------\n";
    }
}

void displayAllAccounts() {
    if (accounts.empty()) {
        std::cout << "No accounts found.\n";
        return;
    }

    for (const auto& account : accounts) {
        std::cout << "Account Number: " << account->getAccountNumber()
            << ", Balance: $" << account->getBalance() << "\n";
        std::cout << "-------------------\n";
    }
}

void showMenu() {
    std::cout << "\nBankEase: Main Menu\n";
    std::cout << "1. Create Customer\n";
    std::cout << "2. Create Staff\n";
    std::cout << "3. Create Account\n";
    std::cout << "4. Deposit to Account\n";
    std::cout << "5. Withdraw from Account\n";
    std::cout << "6. Display All Customers\n";
    std::cout << "7. Display All Staff\n";
    std::cout << "8. Display All Accounts\n";
    std::cout << "9. Exit\n";
}

int main() {
    int choice;

    do {
        showMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            createCustomer();
            break;
        case 2:
            createStaff();
            break;
        case 3:
            createAccount();
            break;
        case 4:
            depositToAccount();
            break;
        case 5:
            withdrawFromAccount();
            break;
        case 6:
            displayAllCustomers();
            break;
        case 7:
            displayAllStaff();
            break;
        case 8:
            displayAllAccounts();
            break;
        case 9:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}