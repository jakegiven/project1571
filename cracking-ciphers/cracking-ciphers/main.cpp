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
    
    try{
        while (getline(cipherFileIn, line)){
            cipher_in[i] = line;
            i++;
    }
    } catch(exception e) {
        cerr << e.what() << endl;
    }
    cipherFileIn.close();
    
    return cipher_in[0];
}

void findAmountOfLetters (){
    
}

void frequencyOfLetters (){
    
}

int main(int argc, const char * argv[]) {
    // handle .txt file input
    string cipher_in = getInputFile(argv);
    
    int letters [26] = {};
    
    int length = 0;
    
    for(int i=0; i < cipher_in.length(); i++){
        switch (cipher_in[i]) {
            case 'A':
                letters[0] = letters[0] + 1;
                break;
            case 'B':
                letters[1] = letters[1] + 1;
                break;
            case 'C':
                letters[2] = letters[2] + 1;
                break;
            case 'D':
                letters[3] = letters[3] + 1;
                break;
            case 'E':
                letters[4] = letters[4] + 1;
                break;
            case 'F':
                letters[5] = letters[5] + 1;
                break;
            case 'G':
                letters[6] = letters[6] + 1;
                break;
            case 'H':
                letters[7] = letters[7] + 1;
                break;
            case 'I':
                letters[8] = letters[8] + 1;
                break;
            case 'J':
                letters[9] = letters[9] + 1;
                break;
            case 'K':
                letters[10] = letters[10] + 1;
                break;
            case 'L':
                letters[11] = letters[11] + 1;
                break;
            case 'M':
                letters[12] = letters[12] + 1;
                break;
            case 'N':
                letters[13] = letters[13] + 1;
                break;
            case 'O':
                letters[14] = letters[14] + 1;
                break;
            case 'P':
                letters[15] = letters[15] + 1;
                break;
            case 'Q':
                letters[16] = letters[16] + 1;
                break;
            case 'R':
                letters[17] = letters[17] + 1;
                break;
            case 'S':
                letters[18] = letters[18] + 1;
                break;
            case 'T':
                letters[19] = letters[19] + 1;
                break;
            case 'U':
                letters[20] = letters[20] + 1;
                break;
            case 'V':
                letters[21] = letters[21] + 1;
                break;
            case 'W':
                letters[22] = letters[22] + 1;
                break;
            case 'X':
                letters[23] = letters[23] + 1;
                break;
            case 'Y':
                letters[24] = letters[24] + 1;
                break;
            case 'Z':
                letters[25] = letters[25] + 1;
                break;
            default:
                cout << "Character not recognized";
                break;
        }
        length++;
    }
    
    cout << "Number of characters in file: " << length << endl;
    
    double frequencies [26] = {};
    
    for(int i = 0; i < 26; i++){
        frequencies[i] = ((double)letters[i]/(double)cipher_in.length())*100;
    }
    
    cout << "Frequency of Letters:" << endl;
    cout << "A: " << letters[0] << "\tFrequency: " << setprecision(5) << frequencies[0] << "%" << endl;
    cout << "B: " << letters[1] << "\tFrequency: " << setprecision(5) << frequencies[1] << "%" << endl;
    cout << "C: " << letters[2] << "\tFrequency: " << setprecision(5) << frequencies[2] << "%" << endl;
    cout << "D: " << letters[3] << "\tFrequency: " << setprecision(5) << frequencies[3] << "%" << endl;
    cout << "E: " << letters[4] << "\tFrequency: " << setprecision(5) << frequencies[4] << "%" << endl;
    cout << "F: " << letters[5] << "\tFrequency: " << setprecision(5) << frequencies[5] << "%" << endl;
    cout << "G: " << letters[6] << "\tFrequency: " << setprecision(5) << frequencies[6] << "%" << endl;
    cout << "H: " << letters[7] << "\tFrequency: " << setprecision(5) << frequencies[7] << "%" << endl;
    cout << "I: " << letters[8] << "\tFrequency: " << setprecision(5) << frequencies[8] << "%" << endl;
    cout << "J: " << letters[9] << "\tFrequency: " << setprecision(5) << frequencies[9] << "%" << endl;
    cout << "K: " << letters[10] << "\tFrequency: " << setprecision(5) << frequencies[10] << "%" << endl;
    cout << "L: " << letters[11] << "\tFrequency: " << setprecision(5) << frequencies[11] << "%" << endl;
    cout << "M: " << letters[12] << "\tFrequency: " << setprecision(5) << frequencies[12] << "%" << endl;
    cout << "N: " << letters[13] << "\tFrequency: " << setprecision(5) << frequencies[13] << "%" << endl;
    cout << "O: " << letters[14] << "\tFrequency: " << setprecision(5) << frequencies[14] << "%" << endl;
    cout << "P: " << letters[15] << "\tFrequency: " << setprecision(5) << frequencies[15] << "%" << endl;
    cout << "Q: " << letters[16] << "\tFrequency: " << setprecision(5) << frequencies[16] << "%" << endl;
    cout << "R: " << letters[17] << "\tFrequency: " << setprecision(5) << frequencies[17] << "%" << endl;
    cout << "S: " << letters[18] << "\tFrequency: " << setprecision(5) << frequencies[18] << "%" << endl;
    cout << "T: " << letters[19] << "\tFrequency: " << setprecision(5) << frequencies[19] << "%" << endl;
    cout << "U: " << letters[20] << "\tFrequency: " << setprecision(5) << frequencies[20] << "%" << endl;
    cout << "V: " << letters[21] << "\tFrequency: " << setprecision(5) << frequencies[21] << "%" << endl;
    cout << "W: " << letters[22] << "\tFrequency: " << setprecision(5) << frequencies[22] << "%" << endl;
    cout << "X: " << letters[23] << "\tFrequency: " << setprecision(5) << frequencies[23] << "%" << endl;
    cout << "Y: " << letters[24] << "\tFrequency: " << setprecision(5) << frequencies[24] << "%" << endl;
    cout << "Z: " << letters[25] << "\tFrequency: " << setprecision(5) << frequencies[25] << "%" << endl;
    
    
    
    
    
    
    return 0;
}
