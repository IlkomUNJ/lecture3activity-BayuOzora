// bank_customer.cpp
#include "bank_customer.h"
#include <iostream>

BankCustomer::BankCustomer(int id, const string& name, double balance) {
    this->id = id;
    this->name = name;
    this->balance = balance;
}

string BankCustomer::getName() const {
    return this->name;
}

int BankCustomer::getId() const {
    return this->id;
}

double BankCustomer::getBalance() const {
    return this->balance;
}

void BankCustomer::setName(const string& newName) {
    this->name = newName;
}

void BankCustomer::setBalance(double amount) {
    this->balance = amount;
}

void BankCustomer::addBalance(double amount) {
    this->balance += amount;
}

bool BankCustomer::withdraw(double amount) {
    if (amount <= this->balance) {
        this->balance -= amount;
        return true;
    }
    return false;
}

void BankCustomer::printInfo() const {
    cout << "Customer ID: " << this->id << endl;
    cout << "Customer Name: " << this->name << endl;
    cout << "Balance: $" << this->balance << endl;
}