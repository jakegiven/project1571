//
//  SubstitutionCipher.cpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//
#include "SubstitutionCipher.hpp"
#include <iostream>
using namespace std;

void FindSubstitutionKeys(string cipherText,double monogram_frequencies[]){
    string plainText;
    
    const char freq[] = {'E','T','A','O','I','N','S','R','H','D','L','U','C','M','F','Y','W','G','P','B','V','K','X','Q','J','Z'};
    char key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    double tmp_mf[26];
    
    for (int i = 0; i < 26; i++) {
        tmp_mf[i] = monogram_frequencies[i];
    }
    
    int found = 0;
    while (!found)
    {
        found = 1;
        for (int i = 0; i < 25; i++) {
            if (tmp_mf[i] < tmp_mf[i + 1])
            {
                double v = tmp_mf[i];
                tmp_mf[i] = tmp_mf[i + 1];
                tmp_mf[i + 1] = v;
                char c = key[i];
                key[i] = key[i + 1];
                key[i + 1] = c;
                found = 0;
            }
        }
    }
    
    string selection = "0";
    while (selection != "3")
    {
        if (selection == "0" || selection == "1")
        {
            for (int i = 0; i < 26; i++)
            {
                cout << key[i] << "->" << freq[i] << endl;
            }
        }
        if (selection == "0" || selection == "2")
        {
            for (int n = 0; n < cipherText.length(); n++)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (cipherText[n] == key[i])
                        plainText = plainText + freq[i];
                }
            }
            
            for (int n = 0; n < 160; n++)
            {
                cout << plainText[n];
            }
        }
        
        cout << "\n\n1. View Key\n2. Switch Charaters\n3.Done (View Plain Text)\n";
        cin >> selection;
        
        if (selection == "2")
        {
            
        }
        else if (selection == "3")
        {
            cout << "Plain Text:\n";
            for (int n = 0; n < cipherText.length(); n++)
            {
                cout << plainText[n];
            }
            
        }
    }
}

