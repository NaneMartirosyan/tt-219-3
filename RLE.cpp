#include <iostream>
#include <cstring>
using namespace std;

class RLE {
public:
    void encode(const char* input, char* encoded) {
        int inputLen = strlen(input);
        int index = 0;

        for (int i = 0; i < inputLen; i++) {
            int count = 1;
            while (i < inputLen - 1 && input[i] == input[i + 1]) {
                count++;
                i++;
            }

            encoded[index++] = input[i];
            encoded[index++] = '0' + count; // Assuming count will be <= 9
        }
        encoded[index] = '\0';
    }

    void decode(const char* encoded, char* decoded) {
        int index = 0;
        int decodedIndex = 0;
        int len = strlen(encoded);

        for (int i = 0; i < len; i += 2) {
            char ch = encoded[i];
            int count = encoded[i + 1] - '0';

            for (int j = 0; j < count; j++) {
                decoded[decodedIndex++] = ch;
            }
        }
        decoded[decodedIndex] = '\0';
    }
};

int main() {
    char input[100], encoded[200], decoded[100];
    RLE rle;

    cout << "Enter a string to encode: ";
    cin >> input;

    rle.encode(input, encoded);
    cout << "Encoded string: " << encoded << endl;

    rle.decode(encoded, decoded);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
