#include <iostream>
#include <string>

class RLECipher {
public:
    std::string encode(const std::string& text) const {
        std::string encodedText;
        int n = text.size();
        
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && text[i] == text[i + 1]) {
                count++;
                i++;
            }
            encodedText += text[i];
            encodedText += std::to_string(count);
        }
        
        return encodedText;
    }

    std::string decode(const std::string& encodedText) const {
        std::string decodedText;
        int n = encodedText.size();
        
        for (int i = 0; i < n; i++) {
            char ch = encodedText[i];
            i++;

            std::string countStr;
            while (i < n && std::isdigit(encodedText[i])) {
                countStr += encodedText[i];
                i++;
            }
            i--; 
            
            int count = std::stoi(countStr);
            decodedText.append(count, ch);
        }
        
        return decodedText;
    }
};

int main() {
    std::string text = "6666AAALLLL";
    
    RLECipher cipher;

    std::string encodedText = cipher.encode(text);
    std::cout << "Encoded Text: " << encodedText << std::endl;

    std::string decodedText = cipher.decode(encodedText);
    std::cout << "Decoded Text: " << decodedText << std::endl;

    return 0;
}
