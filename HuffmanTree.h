#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <functional>

// A structure to represent a Huffman tree node
struct HuffmanNode {
    unsigned char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(unsigned char data, unsigned freq);
    HuffmanNode(unsigned freq, HuffmanNode* left, HuffmanNode* right);
};

// Comparator for the priority queue (MIN-heap)
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b);
};

// Function declarations
void generateCodes(HuffmanNode* root, std::string code, std::map<unsigned char, std::string>& huffmanCodes);
void buildHuffmanTreeAndCodes(const std::map<unsigned char, unsigned>& freqMap, std::map<unsigned char, std::string>& huffmanCodes);

#endif // HUFFMAN_TREE_H
