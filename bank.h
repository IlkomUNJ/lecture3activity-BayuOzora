#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include <string>
#include "bank_customer.h"

using namespace std;

class Bank
{
private:
    string bankName;
    vector<BankCustomer> accounts;
    int customerCount;

public:
    // Constructor
    Bank(const string &name);

    // Getter methods
    string getBankName() const;
    int getCustomerCount() const;
    vector<BankCustomer> getAccounts() const;

    // Customer management methods
    void addCustomer(const BankCustomer &customer);
    void removeCustomer(int customerId);
    BankCustomer *findCustomer(int customerId);
    BankCustomer *findCustomerByName(const string &name);

    // Display methods
    void printAllCustomers() const;
    void printBankInfo() const;

    // Setter methods
    void setBankName(const string &newName);

    // Bank operations
    bool transferMoney(int fromId, int toId, double amount);
    double getTotalBankBalance() const;
    void sortCustomersByBalance();

    // Destructor
    ~Bank();
};

#endif // BANK_H