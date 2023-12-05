#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

HuffmanNode* buildHuffmanTree(const unordered_map<char, unsigned>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    for (const auto& pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);

    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

string encodeMessage(const string& message, const unordered_map<char, string>& huffmanCodes) {
    string encodedMessage = "";
    for (char c : message) {
        encodedMessage += huffmanCodes.at(c);
    }
    return encodedMessage;
}

int main() {
    string message = "hello world";

    unordered_map<char, unsigned> frequencies;
    for (char c : message) {
        frequencies[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(frequencies);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    string encodedMessage = encodeMessage(message, huffmanCodes);

    cout << "Original message: " << message << endl;
    cout << "Encoded message: " << encodedMessage << endl;

   
    return 0;
}
