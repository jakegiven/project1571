//
//  SubstitutionCipher.hpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#ifndef SubstitutionCipher_hpp
#define SubstitutionCipher_hpp

#include <stdio.h>
#include <string>
#include <vector>


std::vector<int>FindSubstitutionKeys(std::string,double monogram_frequencies[], double digram_frequencies[], double trigram_frequencies[]);
std::vector<std::string> DecryptSubstitution(std::string cipherText, std::vector<int> key);
#endif /* SubstitutionCipher_hpp */
