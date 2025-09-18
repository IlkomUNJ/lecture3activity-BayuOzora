#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Item(int id, const string& name, double price, int quantity);
    
    // Getter methods
    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Setter methods - These will be used for simultaneous updates by ID
    void setId(int newId);
    void setName(const string& newName);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    
    // Simultaneous update methods based on ID
    void updateByIdPrice(double newPrice);
    void updateByIdQuantity(int newQuantity);
    void updateByIdName(const string& newName);
    void updateByIdAll(const string& newName, double newPrice, int newQuantity);

    // Display method
    void printInfo() const;
    
    // Utility methods
    double getTotalValue() const; // price * quantity
    bool isInStock() const; // quantity > 0
    
    // Destructor
    ~Item();
};

#endif // ITEM_H