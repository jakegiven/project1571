//
//  solver.hpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#ifndef solver_hpp
#define solver_hpp

#include "frequencies.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
class solver{
public:
    std::string run(const char * argv[]);
    std::string getInputFile(const char * argv[]);
    int testPlainText(std::string plaintext);
    double monogram_frequencies[26];
    double digram_frequencies[676];
    double trigram_frequencies[17576];
    int monograms [26];
    int digrams [676];
    int trigrams [17576];
    double index_of_coincidence;
    std::string cipher_in;
    void findMonograms ();
    void findDigrams ();
    void findTrigrams ();
    void findIC ();


};
#endif /* solver_hpp */
