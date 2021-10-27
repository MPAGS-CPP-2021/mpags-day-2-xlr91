#include "TransformChar.hpp"

std::string transformChar( const char in_char ){
// Uppercase alphabetic characters
    std::string outputText;
    if (std::isalpha(in_char)) {
        outputText += std::toupper(in_char);
        return outputText;
    }

    // Transliterate digits to English words
    switch (in_char) {
        case '0':
            outputText += "ZERO";
            break;
        case '1':
            outputText += "ONE";
            break;
        case '2':
            outputText += "TWO";
            break;
        case '3':
            outputText += "THREE";
            break;
        case '4':
            outputText += "FOUR";
            break;
        case '5':
            outputText += "FIVE";
            break;
        case '6':
            outputText += "SIX";
            break;
        case '7':
            outputText += "SEVEN";
            break;
        case '8':
            outputText += "EIGHT";
            break;
        case '9':
            outputText += "NINE";
            break;
    }
    return outputText;
}
