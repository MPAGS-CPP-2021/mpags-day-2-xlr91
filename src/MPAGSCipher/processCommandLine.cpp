
#include "processCommandLine.hpp"
bool processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    bool& encryptRequested,
    bool& decryptRequested,
    std::string& inputFileName,
    std::string& outputFileName,
    int& key
    ){

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    const std::size_t nCmdLineArgs{args.size()};
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-k") {
            // Handle key option
            // Next element is key unless "-k" is the last argument
            // Should probably check that the key is a positive int, dont have time tho :/
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -k requires an int argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;

            
            } else if(!std::isdigit(args[i + 1][0])){ //if not a digit
                std::cerr << "[error] -k requires an int argument" <<std::endl;
            
            } else {
                // Got filename, so assign value and advance past it
                key = std::stoi(args[i + 1]);
                ++i;
            }

       } else if(args[i] == "--encrypt"){
            encryptRequested = true;

        } else if(args[i] == "--decrypt"){
            decryptRequested = true;
        } 
        
        

        
        else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return 1;
        }
    }
        
    //handle naughty --encrypt and --decrypt use at the same time
    if(encryptRequested && decryptRequested){
        std::cerr << "[error] cannot encrypt and decrypt at same time" <<std::endl;
        return 1;
    }
    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << " placeholder for -k, --encrypt, --decrypt \n \n" //dont have time to properly help text :(
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 1;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 1;
    }
    
    
    return 0;
}

