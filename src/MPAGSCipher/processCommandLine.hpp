#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <cctype>


bool processCommandLine(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    bool& encryptRequested,
    bool& decryptRequested,
    std::string& inputFileName,
    std::string& outputFileName,
    int& key
    );

#endif