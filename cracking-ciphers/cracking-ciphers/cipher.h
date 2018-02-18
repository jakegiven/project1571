//
//  cipher.h
//  cracking-ciphers
//
//  Created by Ryan Nyborg on 2/17/18.
//  Copyright © 2018 Ryan Nyborg. All rights reserved.
//

#ifndef cipher_h
#define cipher_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

string getInputFile(const char * argv[]);
int * findAmountOfLetters (string cipher_in);


#endif /* cipher_h */
