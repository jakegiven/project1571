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
    vector<FrequencyThing> monogram;
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
    string key;
    for(int i = 0 ;i < keyLength; i ++){
        key += "A";
    }
    string text = cipher_in.substr(0,200);
    vector<FrequencyThing> copy;
    for(FrequencyThing x:monograms){
        copy.push_back(x);
    }
    
    
    
    

    
    
    
}


