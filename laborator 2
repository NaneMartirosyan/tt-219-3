#include <iostream>
#include <string>

std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::string result = "";
    for (char ch : plaintext) {
        if (isupper(ch)) {
            result += key[ch - 'A']; 
        } else if (islower(ch)) {
            result += tolower(key[ch - 'a']);
        } else {
            result += ch;  
        }
    }
    return result;
}

std::string decrypt(const std::string& ciphertext, const std::string& key) {
    std::string result = "";
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ \t";
    std::cout<<alphabet;

    for (char ch : ciphertext) {
        if (isupper(ch)) {
            result += alphabet[key.find(ch)];
        } else if (islower(ch)) {
            result += tolower(alphabet[key.find(toupper(ch))]);
        } else {
            result += ch; 
        }
    }
    return result;
}

int main() {
    std::string key = "ZYXWVUTSRQPONMLKJIHGFEDCBA\t"; 
    std::cout<<key;
    std::string message = "NANE MARTIROSYAN NATIONAL POLYTECHNIC UNIVERCITY OF ARMENIA";

    std::string encrypted = encrypt(message, key);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = decrypt(encrypted, key);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
