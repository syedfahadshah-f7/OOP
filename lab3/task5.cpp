#include <iostream>
using namespace std;

class shop
{
    string items[5];
    float prices[5];

public:
    void add_item()
    {
        static int count = 0;
        while (count != 5)
        {
            cout << "Enter Item " << count + 1 << " Name: " << endl;
            cin >> items[count];
            cout << "Enter price of item: " << endl;
            cin >> prices[count];
            count++;
        }
    }
    void fetch_item()
    {
        string fetch;
        cout << "Enter item name to see the details: " << endl;
        cin >> fetch;
        for (int i = 0; i < 5; i++)
        {
            if (fetch == items[i])
            {
                cout << "Price Of Item is: " << prices[i] << endl;
                break;
            }
        }
    }
    void edit_item()
    {
        string update;
        cout << "Enter item name to update the price: " << endl;
        cin >> update;
        for (int i = 0; i < 5; i++)
        {
            if (update == items[i])
            {
                float new_price;
                cout << "Enter New Price: " << endl;
                cin >> new_price;
                prices[i] = new_price;
                break;
            }
        }
    }
    void view_items()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Name of Item " << items[i] << " and price is: " << prices[i] << endl;
        }
    }
    float generate_transcript()
    {
        float bill = 0;
        string product;
        int total_product, quantity;
        cout << "Enter Total number of product: ";
        cin >> total_product;
        for (int i = 0; i < total_product; i++)
        {
            cout << "Enter product name: " << endl;
            cin >> product;
            for (int j = 0; j < 5; j++)
            {
                if (product == items[j])
                {
                    cout << "Enter quantity of product: " << endl;
                    cin >> quantity;
                    bill += prices[j] * quantity;
                }
            }
        }
        cout << "Final Bill :" << bill << "$" << endl;
    }
};
int main()
{
    shop obj;

    obj.add_item();
    obj.edit_item();
    obj.fetch_item();
    obj.view_items();
    obj.generate_transcript();
    return 0;
}
