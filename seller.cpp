#include "seller.h"
#include <iostream>
#include <iomanip>

// Constructor
Seller::Seller(int id, const string& name, BankCustomer* account) 
    : id(id), name(name), account(account) {
    cout << "Seller " << name << " (ID: " << id << ") created successfully." << endl;
}

// Destructor
Seller::~Seller() {
    cout << "Seller " << name << " is being destroyed." << endl;
}

// Getter methods
int Seller::getId() const { 
    return id; 
}

string Seller::getName() const { 
    return name; 
}

BankCustomer* Seller::getAccount() const {
    return account;
}

vector<Item> Seller::getInventory() const {
    return inventory;
}

// Setter methods
void Seller::setId(int newId) { 
    id = newId; 
    cout << "Seller ID updated to: " << newId << endl;
}

void Seller::setName(const string& newName) { 
    string oldName = name;
    name = newName; 
    cout << "Seller name changed from '" << oldName << "' to '" << newName << "'" << endl;
}

void Seller::setAccount(BankCustomer* newAccount) {
    account = newAccount;
    cout << "Seller account updated." << endl;
}

// Inventory management
void Seller::addItem(const Item& item) {
    // Check if item ID already exists
    for (const auto& existingItem : inventory) {
        if (existingItem.getId() == item.getId()) {
            cout << "Error: Item with ID " << item.getId() << " already exists in inventory!" << endl;
            return;
        }
    }
    
    inventory.push_back(item);
    cout << "Item '" << item.getName() << "' (ID: " << item.getId() 
         << ") added to " << name << "'s inventory." << endl;
}

void Seller::removeItem(int itemId) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getId() == itemId) {
            cout << "Removing item: " << it->getName() << " (ID: " << itemId << ")" << endl;
            inventory.erase(it);
            return;
        }
    }
    cout << "Item with ID " << itemId << " not found in inventory!" << endl;
}

Item* Seller::findItem(int itemId) {
    for (auto& item : inventory) {
        if (item.getId() == itemId) {
            return &item;
        }
    }
    return nullptr;
}

void Seller::printInventory() const {
    cout << "\n" << string(60, '=') << endl;
    cout << "         " << name << "'s Inventory (Seller ID: " << id << ")" << endl;
    cout << string(60, '=') << endl;
    
    if (inventory.empty()) {
        cout << "No items in inventory." << endl;
        return;
    }
    
    cout << "Total Items: " << inventory.size() << endl;
    cout << string(60, '-') << endl;
    
    for (const auto& item : inventory) {
        item.printInfo();
        cout << string(40, '-') << endl;
    }
}

// Item modification methods based on ID - SIMULTAN BERDASARKAN ID
bool Seller::updateItemPrice(int itemId, double newPrice) {
    Item* item = findItem(itemId);
    if (!item) {
        cout << "Error: Item with ID " << itemId << " not found!" << endl;
        return false;
    }
    
    double oldPrice = item->getPrice();
    item->setPrice(newPrice);
    
    cout << "=== SIMULTANEOUS UPDATE BY ID ===" << endl;
    cout << "Item ID " << itemId << " price updated:" << endl;
    cout << "Old Price: $" << fixed << setprecision(2) << oldPrice << endl;
    cout << "New Price: $" << fixed << setprecision(2) << newPrice << endl;
    cout << "Update applied simultaneously to all references of ID " << itemId << endl;
    
    return true;
}

bool Seller::updateItemQuantity(int itemId, int newQuantity) {
    Item* item = findItem(itemId);
    if (!item) {
        cout << "Error: Item with ID " << itemId << " not found!" << endl;
        return false;
    }
    
    int oldQuantity = item->getQuantity();
    item->setQuantity(newQuantity);
    
    cout << "=== SIMULTANEOUS UPDATE BY ID ===" << endl;
    cout << "Item ID " << itemId << " quantity updated:" << endl;
    cout << "Old Quantity: " << oldQuantity << endl;
    cout << "New Quantity: " << newQuantity << endl;
    cout << "Update applied simultaneously to all references of ID " << itemId << endl;
    
    return true;
}

bool Seller::updateItemName(int itemId, const string& newName) {
    Item* item = findItem(itemId);
    if (!item) {
        cout << "Error: Item with ID " << itemId << " not found!" << endl;
        return false;
    }
    
    string oldName = item->getName();
    item->setName(newName);
    
    cout << "=== SIMULTANEOUS UPDATE BY ID ===" << endl;
    cout << "Item ID " << itemId << " name updated:" << endl;
    cout << "Old Name: " << oldName << endl;
    cout << "New Name: " << newName << endl;
    cout << "Update applied simultaneously to all references of ID " << itemId << endl;
    
    return true;
}

bool Seller::updateItemAll(int itemId, const string& newName, double newPrice, int newQuantity) {
    Item* item = findItem(itemId);
    if (!item) {
        cout << "Error: Item with ID " << itemId << " not found!" << endl;
        return false;
    }
    
    // Store old values
    string oldName = item->getName();
    double oldPrice = item->getPrice();
    int oldQuantity = item->getQuantity();
    
    // Update all properties simultaneously
    item->setName(newName);
    item->setPrice(newPrice);
    item->setQuantity(newQuantity);
    
    cout << "=== SIMULTANEOUS UPDATE ALL PROPERTIES BY ID ===" << endl;
    cout << "Item ID " << itemId << " - ALL properties updated simultaneously:" << endl;
    cout << "Name:     '" << oldName << "' -> '" << newName << "'" << endl;
    cout << "Price:    $" << fixed << setprecision(2) << oldPrice << " -> $" << newPrice << endl;
    cout << "Quantity: " << oldQuantity << " -> " << newQuantity << endl;
    cout << "ALL updates applied simultaneously to all references of ID " << itemId << endl;
    
    return true;
}

// Sales operations
bool Seller::sellItem(int itemId, int quantity, double& totalPrice) {
    Item* item = findItem(itemId);
    if (!item) {
        cout << "Error: Item with ID " << itemId << " not found!" << endl;
        return false;
    }
    
    if (item->getQuantity() < quantity) {
        cout << "Error: Not enough stock! Available: " << item->getQuantity() 
             << ", Requested: " << quantity << endl;
        return false;
    }
    
    totalPrice = item->getPrice() * quantity;
    
    // Update quantity (simultaneous by ID)
    item->setQuantity(item->getQuantity() - quantity);
    
    // Add money to seller's account
    account->addBalance(totalPrice);
    
    cout << "=== SALE COMPLETED ===" << endl;
    cout << "Item: " << item->getName() << " (ID: " << itemId << ")" << endl;
    cout << "Quantity Sold: " << quantity << endl;
    cout << "Price per item: $" << fixed << setprecision(2) << item->getPrice() << endl;
    cout << "Total Sale: $" << totalPrice << endl;
    cout << "Remaining Stock: " << item->getQuantity() << endl;
    cout << "Seller's New Balance: $" << account->getBalance() << endl;
    
    return true;
}

void Seller::printSellerInfo() const {
    cout << "\n" << string(50, '=') << endl;
    cout << "           SELLER INFORMATION" << endl;
    cout << string(50, '=') << endl;
    cout << "Seller ID: " << id << endl;
    cout << "Seller Name: " << name << endl;
    cout << "Account Balance: $" << fixed << setprecision(2) << account->getBalance() << endl;
    cout << "Total Items in Inventory: " << inventory.size() << endl;
    cout << string(50, '=') << endl;
}