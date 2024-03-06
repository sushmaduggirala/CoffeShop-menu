#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Define a structure to represent a menu item
struct MenuItem {
    string name;
    double price;
};

// Define a class for handling orders and generating bills
class CoffeeShop {
private:
    vector<MenuItem> menu;
    vector<MenuItem> order;

public:
    CoffeeShop() {
        // Initialize the menu
        menu.push_back({"Espresso", 120});
        menu.push_back({"Cappuccino", 250});
        menu.push_back({"Latte", 275});
        menu.push_back({"Black Coffee", 50});
    }

    // Display the menu
    void displayMenu() {
        cout << "Menu:\n";
        for (size_t i = 0; i < menu.size(); ++i) {
            cout << "[" << (i + 1) << "] " << menu[i].name << " - Rs  " << menu[i].price << endl;
        }
    }

    // Take an order
    void takeOrder() {
        int choice;
        cout << "Enter the item number to order (0 to finish): ";
        cin >> choice;

        while (choice != 0 && (choice < 1 || choice > static_cast<int>(menu.size()))) {
            cout << "Invalid choice. Please enter a valid item number: ";
            cin >> choice;
        }

        if (choice != 0) {
            order.push_back(menu[choice - 1]);
            cout << menu[choice - 1].name << " added to the order.\n";
            takeOrder();  // Recursive call to take additional items
        }
    }

    // Calculate the total bill
    double calculateBill() {
        double total = 0.0;
        for (size_t i = 0; i < order.size(); ++i) {
            total += order[i].price;
        }
        return total;
    }

    // Generate a receipt
    void generateReceipt() {
        cout << "\nReceipt:\n";
        cout << setw(20) << left << "Item" << setw(10) << right << "Price\n";
        cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;

        for (size_t i = 0; i < order.size(); ++i) {
            cout << setw(20) << left << order[i].name << setw(10) << right << "Rs" << order[i].price << endl;
        }

        cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
        cout << setw(20) << left << "Total" << setw(10) << right << "Rs" << calculateBill() << endl;
    }
};

int main() {
    CoffeeShop coffeeShop;

    cout << "Welcome to the Coffee Shop!\n";
    coffeeShop.displayMenu();

    coffeeShop.takeOrder();

    cout << "Order complete. Calculating bill...\n";
    coffeeShop.generateReceipt();

    cout << "Thank you for visiting the Coffee Shop!\n";

    return 0;
}

