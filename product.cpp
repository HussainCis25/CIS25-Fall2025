#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    Product(int i, string n, float p) : id(i), name(n), price(p) {
        cout << "Constructor called" << endl;
    }

    ~Product() {
        cout << "Destructor called" << endl;
    }

    void printDetails() {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Price: $" << price << endl;
    }
};

int main() {
    Product p(101, "Notebook", 4.99);

    p.printDetails();

    return 0;
}
