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
#include <map>

using namespace std;

string getInputFile(const char * argv[]);
void findMonograms (string cipher_in, int monograms [26], double monogram_frequencies [26]);
void findDigrams ();


#endif /* cipher_h */
