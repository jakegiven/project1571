//
//  ShiftCipher.hpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#ifndef ShiftCipher_hpp
#define ShiftCipher_hpp

#include <stdio.h>
#include <string>
#include <vector>


std::vector<int>FindShiftKeys(std::string cipherText, double monogram_frequencies[]);
std::vector<std::string> DecryptShift(std::string cipherText, std::vector<int> key);

#endif /* ShiftCipher_hpp */
