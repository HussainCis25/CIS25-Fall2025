#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance = balance + amount;
        cout << "Deposit: $" << amount << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Not enough money for " << item << endl;
        } else {
            balance = balance - cost;
            cout << "Purchased: " << item << " for $" << cost << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);

        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }
};

int main() {
    BankAccount myAccount;

    // Starting deposit
    myAccount.deposit(100);

    // Two purchases
    myAccount.makePurchase("Coffee", 4.5);
    myAccount.makePurchase("Book", 25);

    // Show final balance
    myAccount.displayBalance();

    return 0;
}
