#include <iostream>
using namespace std;

class MatrixRotation {
private:
    int n;
    int matrix[50][50];

public:
    MatrixRotation(int size) : n(size) {}

    void inputMatrix() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void displayMatrix() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void encrypt() {
        int rotated[50][50];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[i][j] = matrix[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rotated[i][j];
            }
        }
    }

    void decrypt() {
        int rotated[50][50];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[i][j] = matrix[j][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rotated[i][j];
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    MatrixRotation matrixRotation(n);

    matrixRotation.inputMatrix();

    cout << "Original Matrix:" << endl;
    matrixRotation.displayMatrix();

    matrixRotation.encrypt();
    cout << "\nEncrypted Matrix :" << endl;
    matrixRotation.displayMatrix();

    matrixRotation.decrypt();
    cout << "\nDecrypted Matrix :" << endl;
    matrixRotation.displayMatrix();

    return 0;
}
