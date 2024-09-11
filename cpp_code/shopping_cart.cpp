#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

class ShoppingCart {
private:
    int itemCodes[MAX_ITEMS];
    string itemNames[MAX_ITEMS];
    double unitPrices[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int itemCount;

public:
    ShoppingCart() : itemCount(0) {}

    // Function to add an item to the shopping list
    void addItem() {
        if (itemCount < MAX_ITEMS) {
            int code, qty;
            string name;
            double price;

            cout << "Enter item code: ";
            cin >> code;

            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter unit price: ";
            cin >> price;

            cout << "Enter quantity: ";
            cin >> qty;

            itemCodes[itemCount] = code;
            itemNames[itemCount] = name;
            unitPrices[itemCount] = price;
            quantities[itemCount] = qty;

            itemCount++;

            cout << "Item added to the list." << endl;
        } else {
            cout << "The shopping list is full. Cannot add more items." << endl;
        }
    }

    // Function to remove an item from the shopping list by item code
    void removeItem() {
        int code;
        cout << "Enter the item code to remove: ";
        cin >> code;

        bool found = false;
        for (int i = 0; i < itemCount; ++i) {
            if (itemCodes[i] == code) {
                found = true;
                for (int j = i; j < itemCount - 1; ++j) {
                    itemCodes[j] = itemCodes[j + 1];
                    itemNames[j] = itemNames[j + 1];
                    unitPrices[j] = unitPrices[j + 1];
                    quantities[j] = quantities[j + 1];
                }
                itemCount--;
                cout << "Item removed from the list." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Item not found in the list." << endl;
        }
    }

    // Function to display the shopping list
    void displayList() {
        double grandTotal = 0.0;

        cout << "\nShopping List:\n";
        cout << "------------------------------------------------\n";
        cout << "Item Code | Item Name               | Unit Price | Quantity | Total\n";
        cout << "------------------------------------------------\n";

        for (int i = 0; i < itemCount; ++i) {
            double total = unitPrices[i] * quantities[i];
            grandTotal += total;

            cout << itemCodes[i] << " | "
                 << itemNames[i] << " | "
                 << unitPrices[i] << " | "
                 << quantities[i] << " | "
                 << total << "\n";
        }

        cout << "------------------------------------------------\n";
        cout << "Grand Total: " << grandTotal << "\n";
    }
};

int main() {
    ShoppingCart cart;
    char choice;

    do {
        cout << "Options:\n";
        cout << "1. Add an item to the list\n";
        cout << "2. Remove an item from the list\n";
        cout << "3. Display shopping list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cart.addItem();
                break;
            case '2':
                cart.removeItem();
                break;
            case '3':
                cart.displayList();
                break;
            case '4':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
