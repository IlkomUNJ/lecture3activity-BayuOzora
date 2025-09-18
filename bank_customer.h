// bank_customer.h
#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include <string>

using namespace std;

class BankCustomer {
private:
    int id;
    string name;
    double balance;

public:
    BankCustomer(int id, const string& name, double balance);

    int getId() const;
    string getName() const;
    double getBalance() const;

    void setName(const string& newName);
    void setBalance(double newBalance);
    void addBalance(double amount);
    bool withdraw(double amount);
    void printInfo() const;
};

#endif // BANK_CUSTOMER_H