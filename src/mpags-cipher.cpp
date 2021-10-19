// standard library includes
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"


//define functions
int main(int argc, char* argv[]){
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    bool encryptRequested{false};
    bool decryptRequested{false};
    bool encrpytFlag{false}; //if true, encrypts, and vice versa
    int key{0};
    std::string inputFile{""};
    std::string outputFile{""};
    
    bool processCLOutput{false};


    processCLOutput = processCommandLine(cmdLineArgs, helpRequested, versionRequested, encryptRequested, decryptRequested, inputFile, outputFile, key);

    
    if(processCLOutput){
        return 1; //indicates that the program shouldnt run
    }

    if(encryptRequested){
        encrpytFlag = true;
    }
    if(decryptRequested){ //just in case
        encrpytFlag = false;
    }
    
    
    

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;
    std::string outputText;
    std::ifstream in_file{inputFile};
    std::ofstream out_file{outputFile};

    // Read in user input from stdin/file
    if (!inputFile.empty()) {
        if(in_file.good()){
            while (in_file >> inputChar) {
                inputText += transformChar(inputChar);
            }
        }
    } else {
        while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
            // If the character isn't alphabetic or numeric, DONT add it
        }
    }

    outputText = runCaesarCipher(inputText, key, encrpytFlag);
    
    // Print out the transliterated text
    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        if(out_file.good()){
            out_file << outputText;
        }
    } else{
        std::cout << outputText << std::endl;
    }

    

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}


