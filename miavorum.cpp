#include <iostream>
#include <string>
#include <iomanip>

class CaesarCipher {
private:
    int shift;

public:
    CaesarCipher(int s) : shift(s) {}

    std::string encrypt(const std::string& plaintext) {
        std::string result;
        for (char ch : plaintext) {
            if (isupper(ch)) {
                result += char(int((ch - 'A' + shift) % 26 + 'A'));
            } else if (islower(ch)) {
                result += char(int((ch - 'a' + shift) % 26 + 'a'));
            } else {
                result += ch;
            }
        }
        return result;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string result;
        for (char ch : ciphertext) {
            if (isupper(ch)) {
                result += char(int((ch - 'A' - shift + 26) % 26 + 'A'));
            } else if (islower(ch)) {
                result += char(int((ch - 'a' - shift + 26) % 26 + 'a'));
            } else {
                result += ch;
            }
        }
        return result;
    }
};

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

    std::string decrypt(const std::string& encryptedText) {
        clearMatrix();
        int index = 0;
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (index < encryptedText.size() && encryptedText[index] != ' ') {
                    matrix[row][col] = encryptedText[index++];
                } else {
                    index++;
                }
            }
        }

        std::string decryptedText;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] != ' ') {
                    decryptedText += matrix[row][col];
                }
            }
        }
        return decryptedText;
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
    int shift;
    std::string plaintext;

    std::cout << "Enter shift for Caesar Cipher: ";
    std::cin >> shift;
    std::cin.ignore();
    std::cout << "Enter plaintext to encrypt with both Caesar and Matrix methods: ";
    std::getline(std::cin, plaintext);

    CaesarCipher caesar(shift);
    std::string encryptedCaesarText = caesar.encrypt(plaintext);
    std::cout << "After Caesar Cipher encryption: " << encryptedCaesarText << std::endl;

    FixedMatrixEncryptor matrixEncryptor(encryptedCaesarText);
    std::string finalEncryptedText = matrixEncryptor.encrypt();
    std::cout << "Final encrypted text (after both Caesar and Matrix methods): " << finalEncryptedText << std::endl;

    std::cout << "\nMatrix used for final encryption:" << std::endl;
    matrixEncryptor.displayMatrix();

    std::string decryptedMatrixText = matrixEncryptor.decrypt(finalEncryptedText);
    std::cout << "\nText after Matrix decryption (Caesar-encrypted text): " << decryptedMatrixText << std::endl;

    std::string decryptedCaesarText = caesar.decrypt(decryptedMatrixText);
    std::cout << "Original text after both decryptions: " << decryptedCaesarText << std::endl;

    return 0;
}
