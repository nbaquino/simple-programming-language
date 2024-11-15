#include <iostream>
#include <vector>
#include "../include/Scanner.h"   // Assuming Scanner.h is in include folder
#include "parser.cpp"             // Include your parser implementation

// Function to test the parser with a given input string
void testParser(const std::string& input) {
    std::cout << "Testing input: " << input << "\n";

    // Initialize the scanner with the input string
    Scanner scanner(input);
    std::vector<Token> tokens = scanner.scanTokens();

    // Initialize the parser with the tokens generated by the scanner
    Parser parser(tokens);
    Sentence* sentence = parser.parseSentence();

    // Check if parsing succeeded and print the parse tree
    if (sentence) {
        printParseTree(sentence, 0);
        delete sentence;  // Clean up
    } else {
        std::cout << "Parsing failed.\n";
    }

    std::cout << "-----------------------\n";
}

int main() {
    // Test cases with various logical expressions
    testParser("(P Or Q) And Q");       // Sentence with parentheses and OR

    return 0;
}
