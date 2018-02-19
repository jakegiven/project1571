//
//  main.cpp
//  cracking-ciphers
//
//  Created by Ryan Nyborg on 2/17/18.
//  Copyright © 2018 Ryan Nyborg. All rights reserved.
//

#include "ShiftCipher.hpp"
#include "SubstitutionCipher.hpp"
#include "solver.hpp"
using namespace std;





int main(int argc, const char * argv[]) {
    // handle .txt file input
    solver runMan;
    runMan.run(argv);
    
    
    
    return 0;
}
