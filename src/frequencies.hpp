//
//  frequencies.hpp
//  Project
//
//  Created by Jake Given on 2/18/18.
//
//

#ifndef frequencies_hpp
#define frequencies_hpp

#include <stdio.h>
#include <string>
#include <vector>

class FrequencyThing{
public:
    std::string c;
    double frequency;
    std::vector<int> loc;
    FrequencyThing();
    FrequencyThing(double frequency, std::string c);
    
    bool operator<(const FrequencyThing& rhs)const{return (rhs.frequency < frequency);};
};

#endif /* frequencies_hpp */
