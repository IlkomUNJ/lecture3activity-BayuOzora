#include <iostream>
#include <string>
#include <vector>

#include "bank.h"
#include "bank_customer.h"
#include "seller.h"
#include "buyer.h"
#include "item.h"

using namespace std;

/**
 * @brief Function to simulate purchase transaction process.
 * * @param buyer Buyer object.
 * @param seller Seller object.
 * @param itemId ID of item to be purchased.
 * @param quantity Quantity of item to be purchased.
 */
void processPurchase(Buyer &buyer, Seller &seller, int itemId, int quantity)
{
    cout << "\n=============================================" << endl;
    cout << "PROCESSING PURCHASE: " << buyer.getName() << " buying from " << seller.getName() << endl;
    cout << "=============================================" << endl;

    Item *itemToBuy = seller.findItem(itemId);

    // 1. Validate if item exists
    if (!itemToBuy)
    {
        cout << "Transaction Failed: Item with ID " << itemId << " not found in store " << seller.getName() << "." << endl;
        return;
    }

    // 2. Validate stock
    if (itemToBuy->getQuantity() < quantity)
    {
        cout << "Transaction Failed: Insufficient stock. Current stock: " << itemToBuy->getQuantity() << ", requested: " << quantity << "." << endl;
        return;
    }

    double totalPrice = itemToBuy->getPrice() * quantity;

    // 3. Validate buyer balance
    if (buyer.getAccount()->getBalance() < totalPrice)
    {
        cout << "Transaction Failed: " << buyer.getName() << " has insufficient balance." << endl;
        cout << "Required: $" << totalPrice << ", Balance: $" << buyer.getAccount()->getBalance() << endl;
        return;
    }

    // 4. Process transaction
    cout << "Validation successful. Starting transaction process..." << endl;

    // Deduct buyer balance
    buyer.getAccount()->withdraw(totalPrice);

    // Process sale on seller side (will add seller balance and reduce stock)
    double salePrice = 0; // This variable will be filled by sellItem method
    seller.sellItem(itemId, quantity, salePrice);

    cout << "\n--- TRANSACTION SUCCESSFUL ---" << endl;
    cout << buyer.getName() << " successfully bought " << quantity << " " << itemToBuy->getName() << " for $" << totalPrice << endl;
    cout << buyer.getName() << "'s new balance: $" << buyer.getAccount()->getBalance() << endl;
    cout << seller.getName() << "'s new balance: $" << seller.getAccount()->getBalance() << endl;
    cout << "=============================================\n"
         << endl;
}

int main()
{
    // 1. Initialize Bank
    cout << "--- System Initialization ---" << endl;
    Bank aBank("Digital Prosperity Bank");

    // 2. Create and add customers to bank
    aBank.addCustomer(BankCustomer(101, "John Doe", 1500.00));       // Seller
    aBank.addCustomer(BankCustomer(201, "Jane Smith", 800.00));      // Buyer
    aBank.addCustomer(BankCustomer(202, "Michael Johnson", 200.00)); // Another buyer

    aBank.printAllCustomers();

    // 3. Create Seller and Buyers
    // IMPORTANT: Get account pointers from Bank object to ensure data consistency
    BankCustomer *sellerAccount = aBank.findCustomer(101);
    BankCustomer *buyerAccount1 = aBank.findCustomer(201);
    BankCustomer *buyerAccount2 = aBank.findCustomer(202);

    if (!sellerAccount || !buyerAccount1 || !buyerAccount2)
    {
        cout << "Error: Failed to find customer accounts. Program terminated." << endl;
        return 1;
    }

    Seller seller(1, "John's General Store", sellerAccount);
    Buyer buyer1(1, "Jane", buyerAccount1);
    Buyer buyer2(2, "Michael", buyerAccount2);

    // 4. Seller adds items to inventory
    cout << "\n--- Seller Adding Inventory ---" << endl;
    seller.addItem(Item(1001, "Notebook", 2.50, 50));
    seller.addItem(Item(1002, "Pencil 2B", 0.50, 100));
    seller.addItem(Item(1003, "Eraser", 1.00, 75));

    seller.printInventory();
    seller.printSellerInfo();

    // 5. Transaction Scenarios
    // Jane buys 10 notebooks and 5 pencils
    processPurchase(buyer1, seller, 1001, 10);
    processPurchase(buyer1, seller, 1002, 5);

    // Michael tries to buy 80 erasers (enough stock, but insufficient money)
    processPurchase(buyer2, seller, 1003, 80);

    // Michael buys 20 erasers (successful)
    processPurchase(buyer2, seller, 1003, 20);

    // 6. Seller updates item prices
    cout << "\n--- Seller Updating Item Prices ---" << endl;
    seller.updateItemPrice(1001, 2.75); // Notebook price increase

    // 7. Display final status
    cout << "\n--- FINAL SYSTEM STATUS ---" << endl;
    seller.printInventory();
    aBank.printAllCustomers();
    aBank.printBankInfo();

    cout << "\n--- SIMULATION COMPLETE ---" << endl;

    return 0;
}
