// buyer.cpp
#include "buyer.h"

Buyer::Buyer(int id, const string& name, BankCustomer* account) 
    : id(id), name(name), account(account) {}

int Buyer::getId() const { 
    return id; 
}

string Buyer::getName() const { 
    return name; 
}

BankCustomer* Buyer::getAccount() const {
    return account;
}

void Buyer::setId(int newId) { 
    id = newId; 
}

void Buyer::setName(const string& newName) { 
    name = newName; 
}

void Buyer::setAccount(BankCustomer* newAccount) {
    account = newAccount;
}