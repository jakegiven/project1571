//
//  main.cpp
//  cracking-ciphers
//
//  Created by Ryan Nyborg on 2/17/18.
//  Copyright © 2018 Ryan Nyborg. All rights reserved.
//

#include "cipher.h"
using namespace std;

string getInputFile(const char * argv[]){
    ifstream cipherFileIn;
    int i = 0;
    string line;
    string cipher_in [] = {};
    
    cipherFileIn.open(argv[1]);
    
    if(!cipherFileIn) {
        cout << "Unable to open file...";
    }
    
    while (getline(cipherFileIn, line)){
        cipher_in[i] = line;
        i++;
    }
    cipherFileIn.close();
    
    return cipher_in[0];
}

int main(int argc, const char * argv[]) {
    // handle .txt file input
    string cipher_in = getInputFile(argv);
    
    cout << cipher_in << endl;
    
    
    
    
    return 0;
}
