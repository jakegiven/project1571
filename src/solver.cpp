//
//  solver.cpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#include "solver.hpp"
#include "ShiftCipher.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
string solver::run(const char * argv[]){
    
    cipher_in = getInputFile(argv);
    
    
    vector<string> plain_text;
    vector<int> potentialKeys;

    
    findMonograms();
    
    findDigrams();
    findTrigrams();
    
    findIC();
    //shift cipher
    //potentialKeys = FindShiftKeys(cipher_in,monogram_frequencies);
    
    //plain_text = DecryptShift(cipher_in, potentialKeys);
    
    //for(int i = 0; i < plain_text.size(); i++) cout << "Key:" << potentialKeys[i] <<"\t" << "Plain Text:" << plain_text[i]<<endl;
    findIC();
    
    if ((index_of_coincidence > 1.68) && (index_of_coincidence < 1.78))
    {
        cout << "Cipher is most likely Shift -> finding possible keys\n";
        potentialKeys = FindShiftKeys(cipher_in, monogram_frequencies);
        plain_text = DecryptShift(cipher_in, potentialKeys);
        
        for (int i = 0; i < plain_text.size(); i++)
        {
            cout << "Testing Key: " << potentialKeys[i] << endl;
            int tmp = testPlainText(plain_text[i]);
            if ( tmp > 20)
            {
                cout << "Possible Decryption as THE/AND count is " << tmp << endl << plain_text[i] << endl << endl;
            }
            else
            {
                cout << "Unlikely Decryption as THE/AND count is " << tmp << endl << endl;
            }
        }
        
    }
    else if (index_of_coincidence >= 1.78)
    {
        cout << "Cipher is most likely Substitution -> finding possible keys\n";
    }
    else if ((index_of_coincidence > 0.95) && (index_of_coincidence < 1.05))
    {
        cout << "Cipher is most likely One-Time Pad -> Good luck finding keys\n";
    }
    return "hi";
}

string solver::getInputFile(const char * argv[]){
    ifstream cipherFileIn;
    int i = 0;
    string line;
    vector<string> cipher_in;
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


int solver::testPlainText(std::string plaintext) {
    
    int occurences;
    occurences = 0;
    
    // test for THE
    for (int i = 0; i < plaintext.length()-2; i++)
    {
        if (plaintext[i] == 'T' && plaintext[i+1] == 'H' && plaintext[i + 2] == 'E')
            occurences++;
    }
    // test for AND
    for (int i = 0; i < plaintext.length() - 2; i++)
    {
        if (plaintext[i] == 'A' && plaintext[i + 1] == 'N' && plaintext[i + 2] == 'D')
            occurences++;
    }
    return occurences;
}

void solver::findMonograms (){
    int length = 0;
    for (int i = 0; i < 26; i++) monograms[i] = 0;
    
    
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
        monogram.push_back(FrequencyThing(((double)monograms[i]/(double)cipher_in.length())*100,"a"));
        monogram.at(i).c = char(i+65);
        //monogram.at(i).frequency =((double)monograms[i]/(double)cipher_in.length())*100;
        monogram_frequencies[i] = ((double)monograms[i]/(double)cipher_in.length())*100;
    }
    sort(monogram.begin(),monogram.end());
    cout << "Top 10 letter frequencies"<<endl;

    for(int i = 0; i < 10; i ++){
        cout << monogram.at(i).c << "\tFrequency:" << monogram.at(i).frequency << endl;
    }
}

void solver::findDigrams () {
    cout << "Digram Occurances: " << endl;
    
    map<string,int> occurences;
    
    string seq("  ");
    for(int i = 1; i < cipher_in.length() - 1; i++)
    {
        seq[0] = cipher_in[i-1];
        seq[1] = cipher_in[i];
        
        //ignore spaces
        if (seq.compare(0,1, " ") && seq.compare(1,1, " ")&&seq.compare(2,1, " "))
        {
            occurences[seq]++;
        }
    }
    
    for(auto iter = occurences.begin(); iter != occurences.end(); ++iter)
    {
        if(iter->second >= 100){
            digram.push_back(FrequencyThing((double)((iter->second)*100)/(cipher_in.length()/2),iter->first));
            //cout << iter->first << "   " << iter->second << "\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
        } else {
            //cout << iter->first << "   " << iter->second << "\t\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
        }
    }
    sort(digram.begin(),digram.end());
    cout << "10 most frequent digrams:" <<endl;
    
    for(int i = 0; i < 10; i ++){
        cout << digram.at(i).c << "\tFrequency:"<<digram.at(i).frequency<<endl;
    }
    cout << endl;
}


void solver::findTrigrams () {
    cout << "Trigram Occurances: " << endl;
    
    map<string,int> occurences;
    
    string seq("   ");
    for(int i = 2; i < cipher_in.length() - 1; i++)
    {
        seq[0] = cipher_in[i-2];
        seq[1] = cipher_in[i-1];
        seq[2] = cipher_in[i];
        
        //ignore spaces
        if (seq.compare(0,1, " ") && seq.compare(1,1, " ")&&seq.compare(2,1, " "))
        {
            
            occurences[seq]++;
        }
    }
    size_t x = 0, y = 0;
    for(auto iter = occurences.begin(); iter != occurences.end(); ++iter)
    {
        if(iter->second >= 100){
            trigram.push_back(FrequencyThing((double)((iter->second)*100)/(cipher_in.length()/2),iter->first));
            while(true){
                x = cipher_in.find(iter->first,y);
                if(x==string::npos) break;
                trigram.back().loc.push_back(x);
                y = x+1;
            }
            x = 0;
            y = 0;
            //cout << iter->first << "   " << iter->second << "\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
        } else {
            trigram.push_back(FrequencyThing((double)((iter->second)*100)/(cipher_in.length()/2),iter->first));
            while(true){
                x = cipher_in.find(iter->first,y);
                if(x==string::npos) break;
                trigram.back().loc.push_back(x);
                y = x+1;
                
            }
            x = 0;
            y = 0;
        //cout << iter->first << "   " << iter->second << "\t\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
        }
    }
    sort(trigram.begin(), trigram.end());
    cout << "5 most common trigrams and locations:" << endl;
    
    for(int i = 0; i < 5; i ++){
        cout << trigram.at(i).c << "\tFrequency:" << trigram.at(i).frequency;
        
        //for(int x:trigram.at(i).loc){
        //    cout <<x << ",";
        //}
        cout << endl;
    }
    //cout << endl;
}

void solver::findIC () {
    // Finds the Index of Coincidence (IC): given a ciphertext string as input, outputs the IC value
    double text_length = (double)cipher_in.length();
    double sum_of_monograms = 0.0;
    
    for(int i = 0; i<26; i++){
        sum_of_monograms = sum_of_monograms + (monograms[i]*(monograms[i]-1));
    }
    //cout << "Index of Coincidence (IC): " << index_of_coincidence << endl;
    index_of_coincidence = (1/(0.0385*(text_length*(text_length-1))))*sum_of_monograms;
}
