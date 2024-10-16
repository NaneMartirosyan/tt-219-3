#include <iostream>
#include <string>

class VigenereCipher {
private:
    std::string key;

    std::string generateKey(const std::string& text) const {
        std::string extendedKey;
        int keyLen = key.size();
        for (int i = 0; i < text.size(); i++) {
            extendedKey += key[i % keyLen];
        }
        return extendedKey;
    }

public:
    
    VigenereCipher(const std::string& key) : key(key) {}

    std::string encrypt(const std::string& text) const {
        std::string encryptedText;
        std::string extendedKey = generateKey(text);
        
        for (size_t i = 0; i < text.size(); i++) {
            char x = (text[i] + extendedKey[i] - 2 * 'A') % 26 + 'A';
            encryptedText += x;
        }
        return encryptedText;
    }

    std::string decrypt(const std::string& encryptedText) const {
        std::string decryptedText;
        std::string extendedKey = generateKey(encryptedText);
        
        for (size_t i = 0; i < encryptedText.size(); i++) {
            char x = (encryptedText[i] - extendedKey[i] + 26) % 26 + 'A';
            decryptedText += x;
        }
        return decryptedText;
    }
};

int main() {
    std::string text = "SOFTWARECHAIR";
    std::string keyword = "DOG";

    VigenereCipher cipher(keyword);

    std::string encryptedText = cipher.encrypt(text);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    std::string decryptedText = cipher.decrypt(encryptedText);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
