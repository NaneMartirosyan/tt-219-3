#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct HuffmanNode {
    char character;             
    int frequency;              
    HuffmanNode* left;         
    HuffmanNode* right;         

    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        if (a->frequency == b->frequency) {
            return a->character > b->character; 
        }
        return a->frequency > b->frequency; 
    }
};

HuffmanNode* buildHuffmanTree(const map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (const auto& pair : frequencies) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* merged = new HuffmanNode('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    return pq.top();
}

void generateHuffmanCodes(HuffmanNode* root, const string& code, map<char, string>& huffmanCodes) {
    if (!root) return;

    if (root->character != '\0') {
        huffmanCodes[root->character] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

void deleteTree(HuffmanNode* root) {
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    map<char, int> frequencies = {
        {'r', 1},
        {'!', 1},
        {'p', 2},
        {'o', 2},
        {'"', 2},
        {'b', 3},
        {'e', 4}
    };

    HuffmanNode* root = buildHuffmanTree(frequencies);

    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Коды Хаффмана:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << "'" << pair.first << "'\t" << pair.second << endl;
    }

    deleteTree(root);

    return 0;
}
