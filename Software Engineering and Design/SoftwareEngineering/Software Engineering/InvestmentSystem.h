#ifndef INVESTMENTSYSTEM_H
#define INVESTMENTSYSTEM_H

#include <string>
#include <vector>
#include <map>

using namespace std;

// Enum for service types - more maintainable than magic numbers
enum class ServiceType {
    Invalid = 0,
    Brokerage = 1,
    Retirement = 2
};

class InvestmentSystem {
private:
    // Structure to represent a customer with their name and service type
    struct Customer {
        string name;
        ServiceType serviceType;
    };
    vector<Customer> customers;         // List of all customers
    string username;                     // Currently logged-in username
    map<string, string> userDatabase;   // username -> password mapping

public:
    InvestmentSystem();
    bool authenticate();
    void displayInfo() const;
    void changeCustomerService();
    int getMenuChoice();

private:
    // Helper methods for better code organization
    bool isValidServiceType(int serviceType) const;
    string getServiceTypeName(ServiceType type) const;
};

#endif // INVESTMENTSYSTEM_H