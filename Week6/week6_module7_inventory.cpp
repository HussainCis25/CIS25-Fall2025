#include <iostream>
#include <string>

using namespace std;

// Item struct as required
struct Item {
    string name;
    int id;
};

// Fill the dynamic array with sorted items
void fillInventory(Item* inventory, int size) {
    for (int i = 0; i < size; ++i) {
        // ids: 1, 2, 3, ... size
        inventory[i].id = i + 1;

        // simple names: "Item 1", "Item 2", ...
        inventory[i].name = "Item " + to_string(i + 1);
    }
}

// Binary search by id
// Returns index if found, -1 if not found
int binarySearchById(Item* inventory, int size, int targetId) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int middle = (low + high) / 2;

        if (inventory[middle].id == targetId) {
            return middle;
        } else if (inventory[middle].id < targetId) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    return -1;
}

int main() {
    const int INVENTORY_SIZE = 100;

    // 1. allocate dynamic array on the heap
    Item* inventory = new Item[INVENTORY_SIZE];

    // 2. fill it with sorted data
    fillInventory(inventory, INVENTORY_SIZE);

    cout << "Inventory created with " << INVENTORY_SIZE << " items." << endl;
    cout << "Each item has an id from 1 to " << INVENTORY_SIZE << "." << endl;
    cout << endl;

    // 3. ask user for an id
    int searchId;
    cout << "Enter an item id to search for: ";
    cin >> searchId;

    // 4. search using binary search
    int index = binarySearchById(inventory, INVENTORY_SIZE, searchId);

    // 5. show result
    if (index != -1) {
        cout << "Item found." << endl;
        cout << "Index: " << index << endl;
        cout << "Name: " << inventory[index].name << endl;
        cout << "Id: " << inventory[index].id << endl;
    } else {
        cout << "Item with id " << searchId << " was not found in the inventory." << endl;
    }

    // 6. free memory
    delete[] inventory;
    inventory = nullptr;

    return 0;
}
