#include<iostream>
#include<vector>
#include<cstdlib> // for rand() function

using namespace std;

class Image {
private:
    int width, height;
    int* data;

public:
    // Constructors
    Image(int h, int w, vector<int>& imagedata) : height(h), width(w) {
        data = new int[w * h];
        for (int i = 0; i < w * h; i++) {
            data[i] = imagedata[i];
        }
    }

    // Copy constructor
    Image(const Image& obj) : width(obj.width), height(obj.height) {
        data = new int[width * height];
        for (int i = 0; i < width * height; i++) {
            data[i] = obj.data[i];
        }
    }

    // Destructor
    ~Image() {
        delete[] data;
    }

    // Display function
    void display() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << data[i * width + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Update function
    void update() {
        for (int i = 0; i < width * height; i++) {
            if (data[i] <= 0) {
                data[i] = rand() % 255 + 1;
            }
        }
    }
};

int main() {
    vector<int> imagedata = {2, 3, 1, 0, -1};
    Image obj1(2, 3, imagedata);
    // Calling copy constructor
    Image obj2(obj1);

    cout << "Displaying Original Data: " << endl;
    obj1.display();
    cout << "Displaying Copy Constructor Data: " << endl;
    obj2.display();

    // Calling update function
    obj1.update();
    obj2.update();

    cout << "Displaying Obj1 Data: " << endl;
    obj1.display();
    cout << "Displaying Obj2 Data: " << endl;
    obj2.display();

    return 0;
}
