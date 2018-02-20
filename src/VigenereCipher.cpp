//
//  VigenereCipher.cpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#include "VigenereCipher.hpp"
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;
int kasiskiTest(vector<FrequencyThing> trigrams){

    vector<int> lengths;
    std::map<std::string,std::map<int,std::vector<int>>> map;//each trigram has its own list of distances and a factor vector
    std::map<int,int> factorCount;
    std::vector<int> factors;
    for(int i = 0; i < trigrams.size(); i ++){
        std::vector<int> distances;
        for(int j = 1; j < trigrams.at(i).loc.size(); j++){
            distances.push_back(trigrams.at(i).loc.at(j) - trigrams.at(i).loc.at(j-1));
        }
        
        
        
        for(int j = 1; j < distances.size(); j ++){
            for(int k = 1; k < distances.at(j); k ++){
                if(distances.at(j)%k == 0){
                factorCount[k] ++;
                }
            }

        }
    }
    std::cout << "Top factors:"<<std::endl;
    int highest = 0,highestCount = 0;
    for(auto iter:factorCount){
        //if(iter.second > 100) std::cout << iter.first << ":" <<iter.second<<std::endl;
        if(iter.second>highestCount&&iter.first>3) {
            highest = iter.first;
            highestCount = iter.second;
        }
        //finds the highest occurance key length above 3
        
    }
    std::cout << highest << " " << highestCount << std::endl;
    
    return highest;
    
}
void vigSolve(int keyLength,string cipher_in,vector<FrequencyThing> monograms){
    //create alphabet frequencies
    vector<FrequencyThing> alphabet;
    alphabet.push_back(FrequencyThing(8.167,"A"));
    alphabet.push_back(FrequencyThing(1.492,"B"));
    alphabet.push_back(FrequencyThing(2.782,"C"));
    alphabet.push_back(FrequencyThing(4.253,"D"));
    alphabet.push_back(FrequencyThing(12.702,"E"));
    alphabet.push_back(FrequencyThing(2.228,"F"));
    alphabet.push_back(FrequencyThing(2.015,"G"));
    alphabet.push_back(FrequencyThing(6.094,"H"));
    alphabet.push_back(FrequencyThing(6.966,"I"));
    alphabet.push_back(FrequencyThing(0.153,"J"));
    alphabet.push_back(FrequencyThing(0.772,"K"));
    alphabet.push_back(FrequencyThing(4.025,"L"));
    alphabet.push_back(FrequencyThing(2.406,"M"));
    alphabet.push_back(FrequencyThing(6.749,"N"));
    alphabet.push_back(FrequencyThing(7.507,"O"));
    alphabet.push_back(FrequencyThing(1.929,"P"));
    alphabet.push_back(FrequencyThing(0.095,"Q"));
    alphabet.push_back(FrequencyThing(5.987,"R"));
    alphabet.push_back(FrequencyThing(6.327,"S"));
    alphabet.push_back(FrequencyThing(9.056,"T"));
    alphabet.push_back(FrequencyThing(2.758,"U"));
    alphabet.push_back(FrequencyThing(0.978,"V"));
    alphabet.push_back(FrequencyThing(2.360,"W"));
    alphabet.push_back(FrequencyThing(0.150,"X"));
    alphabet.push_back(FrequencyThing(1.974,"Y"));
    alphabet.push_back(FrequencyThing(0.074,"Z"));
    string tempString;
    vector<string> keys;
    double ioc = 0.0;
    vector<string> goodKeys;
    double maxioc = 0.0;
    string bestKey;
    
    ifstream dictionary("../../ciphertexts/dictionary.txt");
    if(!dictionary){
        cout << "Not able to open dictionary file, can't do analysis"<<endl;
        return;
    }
    while(getline(dictionary, tempString)){
        if(tempString.length()==keyLength) keys.push_back(tempString);
    }
    
    for(string key:keys){
        tempString = TestDecryptVigenere(cipher_in, key);
        ioc = calcIC(tempString);
        if(ioc > 1.3){
            if(ioc>maxioc){
                maxioc = ioc;
                bestKey = key;
            }
            //goodKeys.push_back(key);
            //cout << "Key:"<< key << " \t Text:" << tempString<<endl;
        }
        
    }
    cout << "Key:"<< bestKey << " \t Text:" << TestDecryptVigenere(cipher_in, bestKey)<<endl;
    //tempString = TestDecryptVigenere(cipher_in, "NTUCSO");
    //ioc = calcIC(tempString);
    //cout << "Key:"<< "NTUCSO" << " \t Text:" << tempString<<endl;

    
}
double calcIC(string cipher_in) {
  // Finds the Index of Coincidence (IC): given a ciphertext string as input, outputs the IC value
  double text_length = (double)cipher_in.length();
    int monograms[26] = {};
  double sum_of_monograms = 0.0;
    double index_of_coincidence= 0.0;
    for(int i = 0; i< cipher_in.size(); i++){
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
    }
  
  for(int i = 0; i<26; i++){
      sum_of_monograms = sum_of_monograms + (monograms[i]*(monograms[i]-1));
  }
  //cout << "Index of Coincidence (IC): " << index_of_coincidence << endl;
  index_of_coincidence = (1/(0.0385*(text_length*(text_length-1))))*sum_of_monograms;
    return index_of_coincidence;
}

string TestDecryptVigenere(string cipher_in, string key){
    string plainText;
    for(int i = 0; i < cipher_in.size(); i ++){
        //plainText[i].push_back(((x - 65 + keys[i])%26)+65);
        char temp =((cipher_in.at(i)-65) - (key.at(i%key.size()) - 65) + 26 )%26 + 65;
        plainText+=temp;
    }
    return plainText;
}
