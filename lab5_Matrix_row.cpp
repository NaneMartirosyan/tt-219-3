// #include <iostream>
// using namespace std;

// class MatrixRotation {
// private:
//     int n;
//     int matrix[50][50];

// public:
//     MatrixRotation(int size) : n(size) {}

//     void inputMatrix() {
//         cout << "Enter the elements of the matrix:" << endl;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 cin >> matrix[i][j];
//             }
//         }
//     }

//     void displayMatrix() const {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }

//     void encrypt() {
//         int rotated[50][50];
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 rotated[i][j] = matrix[j][i];
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 matrix[i][j] = rotated[i][j];
//             }
//         }
//     }

//     void decrypt() {
//         int rotated[50][50];
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 rotated[i][j] = matrix[j][i];
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 matrix[i][j] = rotated[i][j];
//             }
//         }
//     }
// };

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     MatrixRotation matrixRotation(n);

//     matrixRotation.inputMatrix();

//     cout << "Original Matrix:" << endl;
//     matrixRotation.displayMatrix();

//     matrixRotation.encrypt();
//     cout << "\nEncrypted Matrix :" << endl;
//     matrixRotation.displayMatrix();

//     matrixRotation.decrypt();
//     cout << "\nDecrypted Matrix :" << endl;
//     matrixRotation.displayMatrix();

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class FixedMatrixEncryptor {
private:
    char matrix[5][3]; 
    const int rows = 5;
    const int cols = 3;

    void clearMatrix() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = ' ';
    }

    void fillMatrix(const std::string& sentence) {
        clearMatrix();
        int row = 0, col = 0;

        for (char ch : sentence) {
            if (ch == ' ') { 
                col++; 
                if (col >= cols) { 
                    col = 0;
                    row++;
                }
                continue;
            }
            
            matrix[row][col++] = ch;
            
            if (col >= cols) { 
                col = 0;
                row++;
            }
            if (row >= rows) break; 
        }
    }

public:
    FixedMatrixEncryptor(const std::string& sentence) {
        fillMatrix(sentence);
    }

    std::string encrypt() {
        std::string encryptedText;

        
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (matrix[row][col] != ' ') {
                    encryptedText += matrix[row][col];
                }
            }
            encryptedText += ' '; 
        }

        return encryptedText;
    }

    void displayMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << std::setw(2) << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::string sentence = "A big cat 21";
    FixedMatrixEncryptor encryptor(sentence);

    std::cout << "Matrix layout:" << std::endl;
    encryptor.displayMatrix();

    std::cout << "\nEncrypted text: " << encryptor.encrypt() << std::endl;

    return 0;
}

