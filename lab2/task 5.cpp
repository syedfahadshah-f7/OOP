/*programmer:Syed Fahad Faheem Shah
roll num: (23k-0062)
  date:2/26/2024
 */
#include<iostream>
using namespace std;

struct product {
    int product_id;
    string product_name;
    float price, quantity;
};

void add(int id,product products[], string prd_name, float price, float quantity, int count) {
    products[count].product_id = id;
    products[count].product_name = prd_name;
    products[count].price = price;
    products[count].quantity = quantity;
}

void display(int id, product products[], int count) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (id == products[i].product_id) {
            cout << "Product Id: " << products[i].product_id << endl;
            cout << "Product Name: " << products[i].product_name << endl;
            cout << "Product Price: " << products[i].price << endl;
            cout << "Product Quantity: " << products[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Can't find product" << endl;
    }
}

void update(int id, product products[], int count) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (id == products[i].product_id) {
            cout << "Enter new Product Name: " << endl;
            cin >> products[i].product_name;
            cout << "Enter new Product Price: " << endl;
            cin >> products[i].price;
            cout << "Enter new Product Quantity: " << endl;
            cin >> products[i].quantity;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Can't find product" << endl;
    }
}

int main() {
    product products[100];
    int option, cnt = 0, id;
    string prd_name;
    float price, quantity;
    do {
        cout << "Add Product press 1" << endl
             << "Update Product press 2" << endl
             << "Display Product press 3" << endl
             << "Exit press 4" << endl;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter Product ID: " << endl;
                cin >> id;
                cout << "Enter Product Name: " << endl;
                cin >> prd_name;
                cout << "Enter Product Price: " << endl;
                cin >> price;
                cout << "Enter Product Quantity: " << endl;
                cin >> quantity;
                add(id,products, prd_name, price, quantity, cnt);
                cnt++;
                break;
            case 3:
                cout << "Enter Product ID to search details: " << endl;
                cin >> id;
                display(id, products, cnt);
                break;
            case 2:
                cout << "Enter Product ID to update details: " << endl;
                cin >> id;
                update(id, products, cnt);
                break;
            default:
                break;
        }
    } while (option != 4);

    return 0;
}
