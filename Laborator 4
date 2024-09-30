#include <iostream>
#include <string>
#include <vector>

class SubstitutionCipher {
private:
    std::vector<unsigned char> encrypt_key; 
    std::vector<unsigned char> decrypt_key; 

public:
    SubstitutionCipher(const std::vector<unsigned char>& key) {
        encrypt_key = key;
        decrypt_key.resize(256);
        
        for (int i = 0; i < 256; ++i) {
            decrypt_key[encrypt_key[i]] = i;
        }
    }

    std::string encrypt(const std::string& plaintext) {
        std::string result = "";
        for (unsigned char ch : plaintext) {
            result += encrypt_key[ch]; 
        }
        return result;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string result = "";
        for (unsigned char ch : ciphertext) {
            result += decrypt_key[ch];
        }
        return result;
    }
};

int main() {
    std::vector<unsigned char> key(256);
    for (int i = 0; i < 256; ++i) {
        key[i] = 255 - i;
    }

    SubstitutionCipher cipher(key);

    std::string message;
    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);  
    std::string encrypted = cipher.encrypt(message);
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::string decrypted = cipher.decrypt(encrypted);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
