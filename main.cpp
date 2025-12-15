#include "HuffmanTree.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

std::map<unsigned char, unsigned> buildFrequencyMap(const std::string& inputPath) {
    std::ifstream inputFile(inputPath, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file " << inputPath << std::endl;
        exit(1);
    }
    std::map<unsigned char, unsigned> freq;
    unsigned char byte;
    while (inputFile.read(reinterpret_cast<char*>(&byte), 1)) {
        freq[byte]++;
    }
    inputFile.close();
    return freq;
}

int main() {
    std::string inputFileName = "sample_input.txt";

    std::ofstream dummyFile(inputFileName, std::ios::binary);
    if (dummyFile) {
        dummyFile << "This is a test string for the Huffman coding C++ project. This project demonstrates optimal prefix code generation using a min-heap priority queue.";
        dummyFile.close();
        std::cout << "Created a sample file: " << inputFileName << std::endl;
    } else {
        std::cout << "Using existing sample file: " << inputFileName << std::endl;
    }

    std::map<unsigned char, unsigned> freqMap = buildFrequencyMap(inputFileName);
    std::map<unsigned char, std::string> huffmanCodes;
    buildHuffmanTreeAndCodes(freqMap, huffmanCodes);

    std::cout << "\nHuffman Codes Generated:\n";
    std::cout << std::setw(10) << "Byte" << std::setw(10) << "Freq" << std::setw(20) << "Code\n";
    std::cout << "---------------------------------------------------\n";
    for (auto const& [byte, freq] : freqMap) {
        char c = static_cast<char>(byte);
        std::string charRepr = (c >= 32 && c <= 126) ? std::string(1, c) : ("0x" + std::string(2, static_cast<char>((byte >> 4) > 9 ? ((byte >> 4) - 10 + 'A') : ((byte >> 4) + '0'))) + static_cast<char>(((byte & 0x0F) > 9 ? ((byte & 0x0F) - 10 + 'A') : ((byte & 0x0F) + '0'))));
        std::cout << std::setw(10) << charRepr << std::setw(10) << freq << std::setw(20) << huffmanCodes[byte] << std::endl;
    }

    std::cout << "\nProject Execution Complete." << std::endl;
    return 0;
}
