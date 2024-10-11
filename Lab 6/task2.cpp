#include <bits/stdc++.h>

using namespace std;

class Matrix3D {
private:
    int arr[3][3];
    int increment_value;
    int count;

public:
    Matrix3D() {
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                arr[i][j] = 0;
        increment_value = 1;
        count = 0;
    }

    void setIncrement(int increment) {
        if(count != 0) {
            cout << "Cannot set due to count not being zero." << endl;
            return;
        }
        if(increment >= 0) {
            this->increment_value = increment;
        }
    }

    void increment() {
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                arr[i][j] += increment_value;
    }

    double det() {
        return arr[0][0] * (
                                arr[1][1]*arr[2][2]
                                - arr[2][1]*arr[1][2]
                            )
              - arr[0][1] * (
                                arr[1][0]*arr[2][2]
                                - arr[2][0]*arr[1][2]
                            )
              + arr[0][2] * (
                                arr[1][0]*arr[2][1]
                                - arr[2][0]*arr[1][1]
                            );
    }

    Matrix3D& getMatrix() {
        return *this;
    }

    Matrix3D& operator + (const Matrix3D& other) {
        Matrix3D* res = new Matrix3D();
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                res->arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }
        return *res;
    }

    Matrix3D& operator - (const Matrix3D& other) {
        Matrix3D* res = new Matrix3D();
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                res->arr[i][j] = arr[i][j] - other.arr[i][j];
            }
        }
        return *res;
    }

    Matrix3D& operator * (const Matrix3D& other) {
        Matrix3D* res = new Matrix3D();
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                res->arr[i][j] = 0;
                for(int k=0; k<3; k++) {
                    res->arr[i][j] += arr[i][k] * other.arr[k][j];
                }
            }
        }
        return *res;
    }

    operator > (const Matrix3D& other) {
        return det() > other.det();
    }

    operator < (const Matrix3D& other) {
        return det() < other.det();


    operator >= (const Matrix3D& other) {
        return det() >= other.det();
    }

    operator <= (const Matrix3D& other) {
        return det() <= other.det();
    }

    operator == (const Matrix3D& other) {
        return det() == other.det();
    }

    operator != (const Matrix3D& other) {
        return det() != other.det();
    }

    friend istream& operator >> (istream& input, Matrix3D& matrix);
    friend ostream& operator << (ostream& output, Matrix3D& matrix);
};

istream& operator >> (istream& input, Matrix3D& matrix) {
    cout << "Enter Matrix: " << endl;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            input >> matrix.arr[i][j];
    return input;
}

ostream& operator << (ostream& output, Matrix3D& matrix) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            output << matrix.arr[i][j] << " ";
        cout << endl;
    }
    return output;
}

int main() {
    Matrix3D mat1, mat2;
    cin >> mat1;
    cin >> mat2;
    cout << "Multiplication: " << endl;
    cout << mat1*mat2 << endl;
    cout << "Addition: " << endl;
    cout << mat1+mat2 << endl;
    cout << "Subtraction: " << endl;
    cout << mat1-mat2 << endl;
    cout << "Determinant of 1st Matrix: " << endl;
    cout << det(mat1) << endl;

    cout << (mat1 < mat2) << endl;
    cout << (mat1 > mat2) << endl;
    cout << (mat1 < mat2) << endl;
    return 0;
}
