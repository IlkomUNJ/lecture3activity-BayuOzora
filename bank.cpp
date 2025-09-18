// bank.cpp
#include "bank.h"
#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;

// Constructor
Bank::Bank(const string &name) : bankName(name), customerCount(0)
{
    cout << "Bank '" << bankName << "' has been created." << endl;
}

// Destructor
Bank::~Bank()
{
    cout << "Bank '" << bankName << "' is being closed." << endl;
}

// Getter methods
string Bank::getBankName() const
{
    return bankName;
}

int Bank::getCustomerCount() const
{
    return customerCount;
}

vector<BankCustomer> Bank::getAccounts() const
{
    return accounts;
}

// Customer management methods
void Bank::addCustomer(const BankCustomer &customer)
{
    // Check if customer ID already exists
    for (const auto &existingCustomer : accounts)
    {
        if (existingCustomer.getId() == customer.getId())
        {
            cout << "Error: Customer with ID " << customer.getId()
                 << " already exists!" << endl;
            return;
        }
    }

    accounts.push_back(customer);
    customerCount++;
    cout << "Customer " << customer.getName()
         << " (ID: " << customer.getId() << ") added successfully." << endl;
}

void Bank::removeCustomer(int customerId)
{
    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if (it->getId() == customerId)
        {
            cout << "Removing customer: " << it->getName()
                 << " (ID: " << customerId << ")" << endl;
            accounts.erase(it);
            customerCount--;
            return;
        }
    }
    cout << "Customer with ID " << customerId << " not found!" << endl;
}

BankCustomer *Bank::findCustomer(int customerId)
{
    for (auto &customer : accounts)
    {
        if (customer.getId() == customerId)
        {
            return &customer;
        }
    }
    return nullptr;
}

BankCustomer *Bank::findCustomerByName(const string &name)
{
    for (auto &customer : accounts)
    {
        if (customer.getName() == name)
        {
            return &customer;
        }
    }
    return nullptr;
}

// Display methods
void Bank::printAllCustomers() const
{
    string separator(50, '=');
    string dash_line(50, '-');
    string short_dash(30, '-');

    cout << "\n"
         << separator << endl;
    cout << "         " << bankName << " - Customer List" << endl;
    cout << separator << endl;

    if (customerCount == 0)
    {
        cout << "No customers in the bank." << endl;
        return;
    }

    cout << "Total Customers: " << customerCount << endl;
    cout << dash_line << endl;

    for (const auto &customer : accounts)
    {
        customer.printInfo();
        cout << short_dash << endl;
    }
}

void Bank::printBankInfo() const
{
    string separator(40, '=');

    cout << "\n"
         << separator << endl;
    cout << "         BANK INFORMATION" << endl;
    cout << separator << endl;
    cout << "Bank Name: " << bankName << endl;
    cout << "Total Customers: " << customerCount << endl;
    cout << "Total Bank Balance: $" << fixed << setprecision(2)
         << getTotalBankBalance() << endl;
    cout << separator << endl;
}

// Setter methods
void Bank::setBankName(const string &newName)
{
    string oldName = bankName;
    bankName = newName;
    cout << "Bank name changed from '" << oldName
         << "' to '" << newName << "'" << endl;
}

// Bank operations
bool Bank::transferMoney(int fromId, int toId, double amount)
{
    BankCustomer *fromCustomer = findCustomer(fromId);
    BankCustomer *toCustomer = findCustomer(toId);

    if (!fromCustomer)
    {
        cout << "Error: Sender with ID " << fromId << " not found!" << endl;
        return false;
    }

    if (!toCustomer)
    {
        cout << "Error: Recipient with ID " << toId << " not found!" << endl;
        return false;
    }

    if (amount <= 0)
    {
        cout << "Error: Transfer amount must be positive!" << endl;
        return false;
    }

    if (fromCustomer->getBalance() < amount)
    {
        cout << "Error: Insufficient funds! Current balance: $"
             << fromCustomer->getBalance() << endl;
        return false;
    }

    // Perform transfer
    fromCustomer->withdraw(amount);
    toCustomer->addBalance(amount);

    cout << "Transfer successful!" << endl;
    cout << "$" << amount << " transferred from " << fromCustomer->getName()
         << " to " << toCustomer->getName() << endl;

    return true;
}

double Bank::getTotalBankBalance() const
{
    double totalBalance = 0.0;
    for (const auto &customer : accounts)
    {
        totalBalance += customer.getBalance();
    }
    return totalBalance;
}

void Bank::sortCustomersByBalance()
{
    sort(accounts.begin(), accounts.end(),
         [](const BankCustomer &a, const BankCustomer &b)
         {
             return a.getBalance() > b.getBalance(); // Descending order
         });
    cout << "Customers sorted by balance (highest to lowest)." << endl;
}