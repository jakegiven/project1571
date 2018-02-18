//
//  main.cpp
//  cracking-ciphers
//
//  Created by Ryan Nyborg on 2/17/18.
//  Copyright © 2018 Ryan Nyborg. All rights reserved.
//

#include "cipher.h"
#include "ShiftCipher.hpp"
#include <vector>
using namespace std;
double monogram_frequencies [26] = {};
double digram_frequencies [676] = {};

string getInputFile(const char * argv[]){
    ifstream cipherFileIn;
    int i = 0;
    string line;
    vector<string> cipher_in;
    //string cipher_in [] = {};
    char temp[200];
    realpath(argv[1],temp);
    cout << argv[1] << endl<<temp<<endl;
    
    cipherFileIn.open(argv[1]);
    
    if(!cipherFileIn) {
        cout << "Unable to open file...";
    }
    
    try{
        while (getline(cipherFileIn, line)){
            cipher_in.push_back(line);
            //cipher_in[i] = line;
            i++;
        }
    } catch(exception e) {
        cerr << e.what() << endl;
    }
    cipherFileIn.close();
    
    return cipher_in[0];
}

void findMonograms (string cipher_in, int monograms [26], double monogram_frequencies [26]){
    int length = 0;
    double IC = 0.0;
    
    for(int i=0; i < cipher_in.length(); i++){
        switch (cipher_in[i]) {
            case 'A':
                monograms[0] = monograms[0] + 1;
                break;
            case 'B':
                monograms[1] = monograms[1] + 1;
                break;
            case 'C':
                monograms[2] = monograms[2] + 1;
                break;
            case 'D':
                monograms[3] = monograms[3] + 1;
                break;
            case 'E':
                monograms[4] = monograms[4] + 1;
                break;
            case 'F':
                monograms[5] = monograms[5] + 1;
                break;
            case 'G':
                monograms[6] = monograms[6] + 1;
                break;
            case 'H':
                monograms[7] = monograms[7] + 1;
                break;
            case 'I':
                monograms[8] = monograms[8] + 1;
                break;
            case 'J':
                monograms[9] = monograms[9] + 1;
                break;
            case 'K':
                monograms[10] = monograms[10] + 1;
                break;
            case 'L':
                monograms[11] = monograms[11] + 1;
                break;
            case 'M':
                monograms[12] = monograms[12] + 1;
                break;
            case 'N':
                monograms[13] = monograms[13] + 1;
                break;
            case 'O':
                monograms[14] = monograms[14] + 1;
                break;
            case 'P':
                monograms[15] = monograms[15] + 1;
                break;
            case 'Q':
                monograms[16] = monograms[16] + 1;
                break;
            case 'R':
                monograms[17] = monograms[17] + 1;
                break;
            case 'S':
                monograms[18] = monograms[18] + 1;
                break;
            case 'T':
                monograms[19] = monograms[19] + 1;
                break;
            case 'U':
                monograms[20] = monograms[20] + 1;
                break;
            case 'V':
                monograms[21] = monograms[21] + 1;
                break;
            case 'W':
                monograms[22] = monograms[22] + 1;
                break;
            case 'X':
                monograms[23] = monograms[23] + 1;
                break;
            case 'Y':
                monograms[24] = monograms[24] + 1;
                break;
            case 'Z':
                monograms[25] = monograms[25] + 1;
                break;
            default:
                cout << "Character not recognized";
                break;
        }
        length++;
    }
    cout << "Number of characters in file: " << length << endl;
    
    for(int i = 0; i < 26; i++){
        monogram_frequencies[i] = ((double)monograms[i]/(double)cipher_in.length())*100;
    }
    
    cout << "Monogram Occurances:" << endl;
    cout << "A: " << monograms[0] << "\tFrequency: " << setprecision(5) << monogram_frequencies[0] << "%" << endl;
    cout << "B: " << monograms[1] << "\tFrequency: " << setprecision(5) << monogram_frequencies[1] << "%" << endl;
    cout << "C: " << monograms[2] << "\tFrequency: " << setprecision(5) << monogram_frequencies[2] << "%" << endl;
    cout << "D: " << monograms[3] << "\tFrequency: " << setprecision(5) << monogram_frequencies[3] << "%" << endl;
    cout << "E: " << monograms[4] << "\tFrequency: " << setprecision(5) << monogram_frequencies[4] << "%" << endl;
    cout << "F: " << monograms[5] << "\tFrequency: " << setprecision(5) << monogram_frequencies[5] << "%" << endl;
    cout << "G: " << monograms[6] << "\tFrequency: " << setprecision(5) << monogram_frequencies[6] << "%" << endl;
    cout << "H: " << monograms[7] << "\tFrequency: " << setprecision(5) << monogram_frequencies[7] << "%" << endl;
    cout << "I: " << monograms[8] << "\tFrequency: " << setprecision(5) << monogram_frequencies[8] << "%" << endl;
    cout << "J: " << monograms[9] << "\tFrequency: " << setprecision(5) << monogram_frequencies[9] << "%" << endl;
    cout << "K: " << monograms[10] << "\tFrequency: " << setprecision(5) << monogram_frequencies[10] << "%" << endl;
    cout << "L: " << monograms[11] << "\tFrequency: " << setprecision(5) << monogram_frequencies[11] << "%" << endl;
    cout << "M: " << monograms[12] << "\tFrequency: " << setprecision(5) << monogram_frequencies[12] << "%" << endl;
    cout << "N: " << monograms[13] << "\tFrequency: " << setprecision(5) << monogram_frequencies[13] << "%" << endl;
    cout << "O: " << monograms[14] << "\tFrequency: " << setprecision(5) << monogram_frequencies[14] << "%" << endl;
    cout << "P: " << monograms[15] << "\tFrequency: " << setprecision(5) << monogram_frequencies[15] << "%" << endl;
    cout << "Q: " << monograms[16] << "\tFrequency: " << setprecision(5) << monogram_frequencies[16] << "%" << endl;
    cout << "R: " << monograms[17] << "\tFrequency: " << setprecision(5) << monogram_frequencies[17] << "%" << endl;
    cout << "S: " << monograms[18] << "\tFrequency: " << setprecision(5) << monogram_frequencies[18] << "%" << endl;
    cout << "T: " << monograms[19] << "\tFrequency: " << setprecision(5) << monogram_frequencies[19] << "%" << endl;
    cout << "U: " << monograms[20] << "\tFrequency: " << setprecision(5) << monogram_frequencies[20] << "%" << endl;
    cout << "V: " << monograms[21] << "\tFrequency: " << setprecision(5) << monogram_frequencies[21] << "%" << endl;
    cout << "W: " << monograms[22] << "\tFrequency: " << setprecision(5) << monogram_frequencies[22] << "%" << endl;
    cout << "X: " << monograms[23] << "\tFrequency: " << setprecision(5) << monogram_frequencies[23] << "%" << endl;
    cout << "Y: " << monograms[24] << "\tFrequency: " << setprecision(5) << monogram_frequencies[24] << "%" << endl;
    cout << "Z: " << monograms[25] << "\tFrequency: " << setprecision(5) << monogram_frequencies[25] << "%" << endl << endl;
    
    
//    IC = findIC(cipher_in, monograms);
//
//    cout << "Index of Coincidence: " << IC << endl;
}

void findDigrams (string cipher_in, int digrams [676], double digram_frequencies [676]) {
    cout << "Digram Occurances: " << endl;
    
    map<string,int> occurences;
    
    string seq("  ");
    for(int i = 1; i < cipher_in.length() - 1; i++)
    {
        seq[0] = cipher_in[i-1];
        seq[1] = cipher_in[i];
        
        //ignore spaces
        if (seq.compare(0,1, " ") && seq.compare(1,1, " "))
        {
            occurences[seq]++;
        }
    }
    
    for(auto iter = occurences.begin(); iter != occurences.end(); ++iter)
    {
        if(iter->second >= 100){
            cout << iter->first << "   " << iter->second << "\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
        } else {
            cout << iter->first << "   " << iter->second << "\t\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
        }
    }
    cout << endl;
}

void findIC (string cipher_in, int monograms [26]) {
    // Finds the Index of Coincidence (IC): given a ciphertext string as input, outputs the IC value
    double text_length = (double)cipher_in.length();
    double sum_of_monograms = 0.0;
    
    for(int i = 0; i<26; i++){
        sum_of_monograms = sum_of_monograms + (monograms[i]*(monograms[i]-1));
    }

    double index_of_coincidence = (1/(text_length*(text_length-1)))*sum_of_monograms;
    
    cout << "Index of Coincidence (IC): " << index_of_coincidence << endl;
}


int main(int argc, const char * argv[]) {
    // handle .txt file input
    string cipher_in = "";
    cipher_in = getInputFile(argv);
    
    int monograms [26] = {};
    int digrams [676] = {};

    
    vector<string> plain_text;
    vector<int> potentialKeys;

    
    findMonograms(cipher_in, monograms, monogram_frequencies);
    
    findDigrams(cipher_in, digrams, digram_frequencies);
    
    findIC(cipher_in, monograms);
    

    potentialKeys = FindShiftKeys(cipher_in);
    
    plain_text = DecryptShift(cipher_in, potentialKeys);
    
    for(int i = 0; i < plain_text.size(); i++) cout << "Key:" << potentialKeys[i] <<"\t" << "Plain Text:" << plain_text[i]<<endl;
    
    return 0;
}
