#include "InvestmentSystem.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructor: initializes customer list and user accounts
InvestmentSystem::InvestmentSystem() {
    // Initialize customers with sample data
    customers = {
        {"Bob Jones", ServiceType::Brokerage},
        {"Sarah Davis", ServiceType::Retirement},
        {"Amy Friendly", ServiceType::Brokerage},
        {"Johnny Smith", ServiceType::Brokerage},
        {"Carol Spears", ServiceType::Retirement}
    };

    // Initialize user accounts (username -> password)
    // SECURITY WARNING: Hardcoded credentials are a security risk
    // Enhancement: Load credentials from secure external source (database, encrypted config file)
    // Enhancement: Implement password complexity requirements
    userDatabase["admin"] = "admin123";
    userDatabase["manager"] = "manager456";
    userDatabase["user"] = "user789";
    userDatabase["test"] = "123";
}

// Authenticates a user by checking username and password against the database
// Returns true if authentication succeeds, false otherwise
bool InvestmentSystem::authenticate() {
    string inputPassword;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    // SECURITY: Password is visible on screen as user types
    // Enhancement: Use platform-specific methods to hide input (e.g., _getch() on Windows, termios on Unix)
    cin >> inputPassword;

    // Check if username exists in database
    if (userDatabase.find(username) != userDatabase.end()) {
        // Check if password matches
        // SECURITY: Plain text password comparison
        // Enhancement: Compare hashed passwords using constant-time comparison to prevent timing attacks
        if (userDatabase[username] == inputPassword) {
            return true;
        }
    }
    // SECURITY: No account lockout after failed attempts
    // Enhancement: Implement rate limiting and account lockout after N failed attempts
    // Enhancement: Add logging for failed authentication attempts
    return false;
}

// Displays all customer information and the currently logged-in user
void InvestmentSystem::displayInfo() const {
    cout << "\n--- Customer Information ---" << endl;
    cout << "Logged in as: " << username << endl;
    cout << "Service Types: 1 = Brokerage, 2 = Retirement" << endl;
    for (size_t i = 0; i < customers.size(); i++) {
        cout << "Customer " << (i + 1) << ": "
            << customers[i].name << " - Service Type: "
            << getServiceTypeName(customers[i].serviceType)
            << " (" << static_cast<int>(customers[i].serviceType) << ")" << endl;
    }
    cout << endl;
}

// Allows the user to change a customer's service type
// Validates input and updates the customer record
// SECURITY: No role-based access control (RBAC)
// Enhancement: Restrict this operation based on user role (e.g., only admin/manager can modify)
void InvestmentSystem::changeCustomerService() {
    int customerNumber, newService;

    cout << "Which customer do you want to change? (1-"
        << customers.size() << "): ";

    if (!(cin >> customerNumber)) {
        // Handle non-integer input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        return;
    }

    // Validate customer number is within valid range
    if (customerNumber < 1 || customerNumber > static_cast<int>(customers.size())) {
        cout << "Invalid customer number!" << endl;
        return;
    }

    cout << "Enter new service number (1=Brokerage, 2=Retirement): ";
    if (!(cin >> newService)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        return;
    }

    // Validate service type is within valid range
    if (!isValidServiceType(newService)) {
        cout << "Invalid service type! Please enter 1 or 2." << endl;
        return;
    }
    // Enhancement: Add audit logging for data modifications

    // Update the customer's service type (adjust for 0-based indexing)
    customers[customerNumber - 1].serviceType = static_cast<ServiceType>(newService);
    cout << "Service updated successfully to "
        << getServiceTypeName(customers[customerNumber - 1].serviceType) << "!" << endl;
}

// Displays the main menu and gets the user's choice
// Returns -1 if invalid input is provided
int InvestmentSystem::getMenuChoice() {
    int choice;

    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Display Information" << endl;
    cout << "2. Change Customer Choice" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return choice;
}

// Validates if a service type number is valid
bool InvestmentSystem::isValidServiceType(int serviceType) const {
    return serviceType >= static_cast<int>(ServiceType::Brokerage) &&
        serviceType <= static_cast<int>(ServiceType::Retirement);
}

// Returns the string name of a service type
string InvestmentSystem::getServiceTypeName(ServiceType type) const {
    switch (type) {
    case ServiceType::Brokerage:
        return "Brokerage";
    case ServiceType::Retirement:
        return "Retirement";
    default:
        return "Unknown";
    }
}

