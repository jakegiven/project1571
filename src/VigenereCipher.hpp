//
//  VigenereCipher.hpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#ifndef VigenereCipher_hpp
#define VigenereCipher_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "frequencies.hpp"
double calcIC(std::string cipher_in);
std::string TestDecryptVigenere(std::string cipher_in, std::string key);

    int kasiskiTest(std::vector<FrequencyThing> trigrams);
void vigSolve(int keyLength,std::string cipher_in, std::vector<FrequencyThing> monogram, std::vector<FrequencyThing> trigram);


#endif /* VigenereCipher_hpp */
