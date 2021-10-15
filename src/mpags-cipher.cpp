// standard library includes
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
 
#include "TransformChar.hpp"
#include "processCommandLine.hpp"


//define functions
int main(int argc, char* argv[]){
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    bool processCLOutput{false};


    processCLOutput = processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile);

    
    if(processCLOutput){
        return 1; //indicates that the program shouldnt run
    }
    
    

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;
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

    // Print out the transliterated text
    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        if(out_file.good()){
            out_file << inputText;
        }
    } else{
        std::cout << inputText << std::endl;
    }

    

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}


