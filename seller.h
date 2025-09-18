#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <vector>
#include "bank_customer.h"
#include "item.h"

using namespace std;

class Seller {
private:
    int id;
    string name;
    BankCustomer* account;
    vector<Item> inventory;

public:
    // Constructor
    Seller(int id, const string& name, BankCustomer* account);
    
    // Getter methods
    int getId() const;
    string getName() const;
    BankCustomer* getAccount() const;
    vector<Item> getInventory() const;
    
    // Setter methods
    void setId(int newId);
    void setName(const string& newName);
    void setAccount(BankCustomer* newAccount);
    
    // Inventory management
    void addItem(const Item& item);
    void removeItem(int itemId);
    Item* findItem(int itemId);
    void printInventory() const;
    
    // Item modification methods based on ID
    bool updateItemPrice(int itemId, double newPrice);
    bool updateItemQuantity(int itemId, int newQuantity);
    bool updateItemName(int itemId, const string& newName);
    bool updateItemAll(int itemId, const string& newName, double newPrice, int newQuantity);
    
    // Sales operations
    bool sellItem(int itemId, int quantity, double& totalPrice);
    void printSellerInfo() const;
    
    // Destructor
    ~Seller();
};

#endif // SELLER_H