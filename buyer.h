// buyer.h
#ifndef BUYER_H
#define BUYER_H

#include <string>
#include "bank_customer.h"

using namespace std;

class Buyer {
private:
    int id;
    string name;
    BankCustomer* account;

public:
    Buyer(int id, const string& name, BankCustomer* account);

    int getId() const;
    string getName() const;
    BankCustomer* getAccount() const;

    void setId(int newId);
    void setName(const string& newName);
    void setAccount(BankCustomer* newAccount);
};

#endif // BUYER_H