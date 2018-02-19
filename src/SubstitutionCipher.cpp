//
//  SubstitutionCipher.cpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//
#include "SubstitutionCipher.hpp"
#include <iostream>



std::vector<int>FindSubstitutionKeys(std::string cipherText,double monogram_frequencies[],double digram_frequencies[], double trigram_frequencies[]){
    std::vector<int> keys;
    for(int i = 0; i < 26; i ++){
        if(monogram_frequencies[i] > 10){
            keys.push_back(('A' - (i+65)+26)%26);
            keys.push_back(('E' - (i+65) +26)%26);
            keys.push_back(('O' - (i+65) +26)%26);
        }
    }
    for(int x:keys){
        std::cout << x <<std::endl;
    }
    
    return keys;
}

std::vector<std::string> DecryptSubstitution(std::string cipherText, std::vector<int> keys){
    std::vector<std::string> plainText;
    //std::vector<int> letters;
    for(int i = 0; i < keys.size(); i ++){
        plainText.push_back("");
        for(char x:cipherText){
            plainText[i].push_back(((x - 65 + keys[i])%26)+65);
        }
    }
    return plainText;
}
