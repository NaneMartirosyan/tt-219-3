#include <string>
#include <vector>
#include <iostream>

class LZ77 {
public:  
    struct Token {
        int offset;     
        int length;     
        char nextChar;  

        Token(int o, int l, char c) : offset(o), length(l), nextChar(c) {}
    };

private:
    const int WINDOW_SIZE = 4096;    
    const int LOOKAHEAD_SIZE = 16;   

Token findLongestMatch(const std::string& data, int currentPos) {
        int maxLength = 0;
        int bestOffset = 0;
        int searchStart = std::max(0, currentPos - WINDOW_SIZE);
        int lookaheadEnd = std::min(currentPos + LOOKAHEAD_SIZE, (int)data.length());

        for (int i = searchStart; i < currentPos; i++) {
            int currentLength = 0;
            while ((currentPos + currentLength) < lookaheadEnd && 
                   data[i + currentLength] == data[currentPos + currentLength] &&
                   currentLength < LOOKAHEAD_SIZE) {
                currentLength++;
            }

            if (currentLength > maxLength) {
                maxLength = currentLength;
                bestOffset = currentPos - i;
            }
        }

        char nextChar = (currentPos + maxLength < data.length()) ? 
                       data[currentPos + maxLength] : '\0';

        return Token(bestOffset, maxLength, nextChar);
    }

public:
    std::vector<Token> compress(const std::string& input) {
        std::vector<Token> compressed;
        int currentPos = 0;

        while (currentPos < input.length()) {
            Token token = findLongestMatch(input, currentPos);
            compressed.push_back(token);
            currentPos += token.length + 1;
        }

        return compressed;
    }

    std::string decompress(const std::vector<Token>& compressed) {
        std::string result;

        for (const Token& token : compressed) {
            if (token.length > 0) {
                int start = result.length() - token.offset;
                for (int i = 0; i < token.length; i++) {
                    result += result[start + i];
                }
            }
            if (token.nextChar != '\0') {
                result += token.nextChar;
            }
        }

        return result;
    }

    void printCompressed(const std::vector<Token>& compressed) {
        for (const Token& token : compressed) {
            std::cout << "<" << token.offset << "," 
                     << token.length << "," 
                     << token.nextChar << "> ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LZ77 compressor;
    std::string input = "The compression and the decompression leave an impression. Hahahahaha!";
    
    std::vector<LZ77::Token> compressed = compressor.compress(input);
    
    std::cout << "Compressed: ";
    compressor.printCompressed(compressed);
    
    std::string decompressed = compressor.decompress(compressed);
    
    std::cout << "Original: " << input << std::endl;
    std::cout << "Decompressed: " << decompressed << std::endl;
    std::cout << "Successful: " << (input == decompressed ? "Yes" : "No") << std::endl;
    
    return 0;
}
