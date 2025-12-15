#include "HuffmanTree.h"
#include <queue>

HuffmanNode::HuffmanNode(unsigned char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
HuffmanNode::HuffmanNode(unsigned freq, HuffmanNode* left, HuffmanNode* right) : data(0), freq(freq), left(left), right(right) {}

bool CompareNodes::operator()(HuffmanNode* a, HuffmanNode* b) {
    return a->freq > b->freq;
}

void generateCodes(HuffmanNode* root, std::string code, std::map<unsigned char, std::string>& huffmanCodes) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
        return;
    }
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

void buildHuffmanTreeAndCodes(const std::map<unsigned char, unsigned>& freqMap, std::map<unsigned char, std::string>& huffmanCodes) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;

    for (auto const& [byte, freq] : freqMap) {
        pq.push(new HuffmanNode(byte, freq));
    }

    while (pq.size() > 1) {
        HuffmanNode *left = pq.top(); pq.pop();
        HuffmanNode *right = pq.top(); pq.pop();
        HuffmanNode* merged = new HuffmanNode(left->freq + right->freq, left, right);
        pq.push(merged);
    }

    if (!pq.empty()) {
        HuffmanNode* root = pq.top();
        generateCodes(root, "", huffmanCodes);
    }
}
