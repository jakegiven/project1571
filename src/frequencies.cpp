//
//  frequencies.cpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#include "frequencies.hpp"
FrequencyThing::FrequencyThing(){
    c = "";
    frequency = 0;
    //loc only used for trigrams/kasiski test
}
FrequencyThing::FrequencyThing(double frequency, std::string c){
    this->c = c;
    this->frequency = frequency;
}
