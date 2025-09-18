#include "item.h"
#include <iostream>
#include <iomanip>

// Constructor
Item::Item(int id, const string& name, double price, int quantity) 
    : id(id), name(name), price(price), quantity(quantity) {
    cout << "Item '" << name << "' (ID: " << id << ") created." << endl;
}

// Destructor
Item::~Item() {
    cout << "Item '" << name << "' (ID: " << id << ") is being destroyed." << endl;
}

// Getter methods
int Item::getId() const { 
    return id; 
}

string Item::getName() const { 
    return name; 
}

double Item::getPrice() const { 
    return price; 
}

int Item::getQuantity() const { 
    return quantity; 
}

// Setter methods
void Item::setId(int newId) { 
    id = newId; 
}

void Item::setName(const string& newName) { 
    name = newName; 
}

void Item::setPrice(double newPrice) { 
    price = newPrice; 
}

void Item::setQuantity(int newQuantity) { 
    quantity = newQuantity; 
}

// Simultaneous update methods based on ID
void Item::updateByIdPrice(double newPrice) {
    cout << "*** SIMULTANEOUS UPDATE BY ID " << id << " ***" << endl;
    cout << "Updating price from $" << fixed << setprecision(2) << price 
         << " to $" << newPrice << endl;
    price = newPrice;
    cout << "Price updated simultaneously for all references with ID " << id << endl;
}

void Item::updateByIdQuantity(int newQuantity) {
    cout << "*** SIMULTANEOUS UPDATE BY ID " << id << " ***" << endl;
    cout << "Updating quantity from " << quantity << " to " << newQuantity << endl;
    quantity = newQuantity;
    cout << "Quantity updated simultaneously for all references with ID " << id << endl;
}

void Item::updateByIdName(const string& newName) {
    cout << "*** SIMULTANEOUS UPDATE BY ID " << id << " ***" << endl;
    cout << "Updating name from '" << name << "' to '" << newName << "'" << endl;
    name = newName;
    cout << "Name updated simultaneously for all references with ID " << id << endl;
}

void Item::updateByIdAll(const string& newName, double newPrice, int newQuantity) {
    cout << "*** SIMULTANEOUS UPDATE ALL PROPERTIES BY ID " << id << " ***" << endl;
    cout << "Updating ALL properties simultaneously:" << endl;
    cout << "Name: '" << name << "' -> '" << newName << "'" << endl;
    cout << "Price: $" << fixed << setprecision(2) << price << " -> $" << newPrice << endl;
    cout << "Quantity: " << quantity << " -> " << newQuantity << endl;
    
    name = newName;
    price = newPrice;
    quantity = newQuantity;
    
    cout << "ALL properties updated simultaneously for all references with ID " << id << endl;
}

void Item::printInfo() const {
    cout << "Item ID: " << id << endl;
    cout << "Item Name: " << name << endl;
    cout << "Price: $" << fixed << setprecision(2) << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Value: $" << fixed << setprecision(2) << getTotalValue() << endl;
    cout << "In Stock: " << (isInStock() ? "Yes" : "No") << endl;
}

double Item::getTotalValue() const {
    return price * quantity;
}

bool Item::isInStock() const {
    return quantity > 0;
}