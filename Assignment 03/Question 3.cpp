#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix
{
protected:
    vector<vector<T>> data;
    int row, col;

public:
    Matrix(int rows, int cols) : row(rows), col(cols), data(rows, vector<T>(cols)) {}

    void set_value(int i, int j, T value)
    {
        data[i][j] = value;
    }

    T get_value(int i, int j)
    {
        return data[i][j];
    }

    vector<vector<T>> operator*(Matrix<T> &obj)
    {
        int m = row;
        int n = obj.col;
        int p = col;

        vector<vector<T>> result(m, vector<T>(n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < p; ++k)
                {
                    result[i][j] += data[i][k] * obj.data[k][j];
                }
            }
        }
        return result;
    }

    vector<vector<T>> operator+(Matrix<T> &obj)
    {
        int m = row;
        int n = col;
        vector<vector<T>> result(m, vector<T>(n));
        if (m == obj.row && n == obj.col)
        {

            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    result[i][j] = data[i][j] + obj.data[i][j];
                }
            }

            return result;
        }
        else
        {
            cout << "Addition could not be possible" << endl;
        }
        return result;
    }

    vector<vector<T>> operator-(Matrix<T> &obj)
    {
        int m = row;
        int n = col;
        vector<vector<T>> result(m, vector<T>(n));
        if (m == obj.row && n == obj.col)
        {

            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    result[i][j] = data[i][j] - obj.data[i][j];
                }
            }
            return result;
        }
        else
        {
            cout << "Subtraction could not be possible" << endl;
        }
        return result;
    }

    virtual void display() = 0;
};

template <typename T>
class intMatrix : public Matrix<T>
{
public:
    intMatrix(int m, int n) : Matrix<T>(m, n) {}

    void display() override
    {
        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->col; ++j)
            {
                cout << this->data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

template <typename T>
class doubleMatrix : public Matrix<T>
{
public:
    doubleMatrix(int m, int n) : Matrix<T>(m, n) {}

    void display() override
    {
        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->col; ++j)
            {
                cout << this->data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    intMatrix<int> intMat(3, 3);
    doubleMatrix<double> doubleMat(3, 3);
    intMatrix<int> intMat2(3, 3);
    doubleMatrix<double> doubleMat2(3, 3);

    // Set some values for demonstration Matrix 1
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            intMat.set_value(i, j, i * 3 + j);
            doubleMat.set_value(i, j, i * 3 + j + 0.5);
        }
    }

    // Set some values for demonstration Matrix 2
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            intMat2.set_value(i, j, i * 8 + j); // corrected from intMat to intMat2
            doubleMat2.set_value(i, j, i * 8 + j + 0.5); // corrected from doubleMat to doubleMat2
        }
    }

    // displaying Matrix 1
    cout << "Integer Matrix1:" << endl;
    intMat.display();

    cout << "\nDouble Matrix1:" << endl;
    doubleMat.display();

    // displaying Matrix 2
    cout << "\nInteger Matrix2:" << endl;
    intMat2.display();

    cout << "\nDouble Matrix2:" << endl;
    doubleMat2.display();

    // Adding
    cout << "\nDoing addition Of int matrices: " << endl;
    auto intAddResult = intMat + intMat2;
    cout << "\nResultant matrix:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << intAddResult[i][j] << " ";
        }
        cout << endl;
    }
    // Substacting
    cout << "\nDoing substraction Of int matrices: " << endl;
     intAddResult = intMat - intMat2;
    cout << "\nResultant matrix:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << intAddResult[i][j] << " ";
        }
        cout << endl;
    }
     // multiplication
    cout << "\nDoing multiplication Of double matrices: " << endl;
    auto doubleAddResult = doubleMat * doubleMat2;
    cout << "\nResultant matrix:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << doubleAddResult[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
