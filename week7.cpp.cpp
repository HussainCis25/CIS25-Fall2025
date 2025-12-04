#include <iostream>
#include <string>
using namespace std;

// Struct that stores item name and id
struct Item {
    string name;
    int id;
};

// Binary search to look for an ID inside the array
int binarySearch(Item* arr, int size, int targetID) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].id == targetID) {
            return mid; // found
        }
        else if (arr[mid].id < targetID) {
            left = mid + 1; // go right
        }
        else {
            right = mid - 1; // go left
        }
    }

    return -1; // not found
}

int main() {

    int size = 100;

    // allocate memory for 100 items
    Item* inventory = new Item[size];

    // sample names (sorted alphabetically)
    string sampleNames[100] = {
        "Apple","Banana","Bottle","Cable","Camera","Chair","Charger","Desk","Door",
        "Earphones","Envelope","Fan","Folder","Fork","Glass","Gloves","Hammer","Hat",
        "Headset","Keyboard","Knife","Lamp","Laptop","Marker","Mask","Mirror","Mouse",
        "Mug","Notebook","Orange","Paper","Pen","Pencil","Phone","Plate","Plug",
        "Poster","Remote","Rope","Router","Scissors","Screw","Screwdriver","Shirt",
        "Shoes","Soap","Spoon","Stapler","Sticker","Table","Tablet","Tape","Teapot",
        "Thermos","Towel","Toy","USB","Umbrella","Vacuum","Vase","Wallet","Watch",
        "WaterBottle","Wire","Wrench","ZebraTool",
        "Item1","Item2","Item3","Item4","Item5", "Item6","Item7","Item8","Item9",
        "Item10","Item11","Item12","Item13","Item14","Item15","Item16","Item17",
        "Item18","Item19","Item20","Item21","Item22","Item23","Item24","Item25",
        "Item26","Item27","Item28","Item29","Item30"
    };

    // fill inventory with names and IDs
    for (int i = 0; i < size; i++) {
        inventory[i].name = sampleNames[i];
        inventory[i].id = 1000 + i; // IDs start from 1000
    }

    int targetID;
    cout << "Enter the ID you want to search for: ";
    cin >> targetID;

    // searching for ID using binary search
    int index = binarySearch(inventory, size, targetID);

    if (index != -1) {
        cout << "Item Found!\n";
        cout << "Name: " << inventory[index].name << endl;
        cout << "ID: " << inventory[index].id << endl;
    }
    else {
        cout << "Item with ID " << targetID << " not found.\n";
    }

    // free memory
    delete[] inventory;

    return 0;
}
