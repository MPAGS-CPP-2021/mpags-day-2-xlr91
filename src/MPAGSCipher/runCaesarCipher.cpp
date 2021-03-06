#include "runCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText, 
                            const size_t key, const bool encrypt){
    
    //initialise variables and alphabet containers
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string outText;
    int loc{0}; 
    int key_s = key; //to get around unsigned integers
    

    for(char ch : inputText){
        //std::cout << alphabet.find(ch) << std::endl;
        loc = alphabet.find(ch);
        if(encrypt){
            outText += alphabet[(26 + ((loc + key_s) % 26)) % 26];
            //std::cout << (26 + ((alphabet.find(ch) + key) % 26)) % 26 ;
            //outText += alphabet[(alphabet.find(ch) + key) % 26]; //broken
        } else{
            outText += alphabet[(26 + ((loc - key_s) % 26)) % 26];

        }
        
    }

    return outText;

}
