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
void vigSolve(int keyLength,string cipher_in, vector<FrequencyThing> monograms, vector<FrequencyThing> trigrams){
    //create alphabet frequencies
    vector<FrequencyThing> alphabet;
    vector<FrequencyThing> monogram;
    int iter = 0;
    int start_iter = 0;
    string key = "";
    
    while (start_iter < keyLength){
    
        map<string,int> occurences;
        
        string seq("  ");

        for(iter = start_iter; iter < cipher_in.length(); iter++)
        {
            seq[0] = cipher_in[iter];
            occurences[seq]++;
            iter = (iter + keyLength) - 1;
        }
        
        int highest_occuring_number = 0; // takes the letter associated with the highest occuring letter
        char highest_occuring_letter = 'A';
        char temp_letter;
        
        for(auto iter = occurences.begin(); iter != occurences.end(); ++iter)
        {
            //if(iter->second >= 100){
            //monogram.push_back(FrequencyThing((double)((iter->second)*100)/(cipher_in.length()/2),iter->first));
            if(highest_occuring_number < iter->second){
                highest_occuring_number = iter->second;
                highest_occuring_letter = iter->first[0];
                // map the highest occuring letter to the letter E in the English language to find key for that letter.
                int diff = highest_occuring_letter - 'E'; //'c' - 'a' = 2
                temp_letter = diff + 'A'; //add 'a' and subtract 1 to normalize it
            }

//            cout << iter->first << "   " << iter->second << "\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
            //} else {
            //cout << iter->first << "   " << iter->second << "\t\tFrequency: " << (double)((iter->second)*100)/(cipher_in.length()/2) << "%" << endl;
            //}
        }
        key = key + temp_letter;
        start_iter++;
    }

    string decrypted_message = "";
    int k = 0;
    // decrypt the message
    for(int j = 0; j < cipher_in.length(); j++){
        int difference = (cipher_in[j] - key[k]) % 26;
        
        if(difference < 0){
            difference = difference + 26;
        }
        
        char temp = difference + 'A';
        decrypted_message = decrypted_message + temp;
        k++;
        
        if(k == keyLength){
            k = 0;
        }
    }
    
    cout << "Decrypted Message:" << endl << decrypted_message << endl;

}


