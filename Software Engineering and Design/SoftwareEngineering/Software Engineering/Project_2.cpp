#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <map> 
#include "InvestmentSystem.cpp"

using namespace std;

/*
 * SECURITY CONSIDERATIONS FOR THIS APPLICATION:
 * 
 * Current Vulnerabilities:
 * 1. Plain text password storage and comparison
 * 2. Hardcoded credentials in source code
 * 3. Password visible during input
 * 4. No account lockout or rate limiting
 * 5. No role-based access control
 * 6. No audit logging
 * 7. No session timeout
 * 8. Insufficient input validation on service types
 * 
 * Recommended Enhancements:
 * - Implement password hashing (bcrypt, SHA-256)
 * - Use external secure credential storage
 * - Hide password input on console
 * - Add authentication rate limiting
 * - Implement RBAC for operations
 * - Add comprehensive audit trail
 * - Implement session management with timeout
 * - Validate all inputs against expected ranges
 */





int main() {


cout << "Hello! Welcome to our Investment Company" << endl;
    cout << "\n=== Available Accounts ===" << endl;
    //cout << "admin / admin123" << endl;
    //cout << "manager / manager456" << endl;
    //cout << "user / user789" << endl;
    //cout << "test / 123" << endl;
   cout << "==========================\n" << endl;

    // Authentication loop - continue until user successfully logs in
    // SECURITY: Unlimited authentication attempts allowed
    // Enhancement: Limit retry attempts and add delay between failed attempts
    // Enhancement: Implement session timeout for security
    while (!system.authenticate()) {
        cout << "Access Denied! Invalid username or password.\n" << endl;
    }

    cout << "Access Granted!\n" << endl;

    // Main program loop - display menu and process user choices until exit
    int choice;
    do {
        choice = system.getMenuChoice();

        switch (choice) {
        case 1:  // Display customer information
            system.displayInfo();
            break;
        case 2:  // Change a customer's service type
            system.changeCustomerService();
            break;
        case 3:  // Exit the program
            cout << "Exiting. Goodbye!" << endl;
            break;
        default:  // Handle invalid menu choices
            cout << "Invalid option. Please select 1-3." << endl;
        }

    } while (choice != 3);

    return 0;
}
