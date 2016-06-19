//
//  maxdrawdown.cpp
//  maxdrawdown
//
//  Created by cjh on 4/30/16.
//  Copyright © 2016 tokyotx. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    // Max drawdown - return the maximum decline in a series of PnL numbers
    
    int pnllist[] {100, 1, 90, 2, 80, 3};
    
    int s = sizeof(pnllist)/sizeof(int);
    cout << "s = " << s << endl;
    
    int max = 0;
    int min = 0;
    int maxdd = 0;
    
    for (int i=0; i < s; i++) {
        
        int p = pnllist[i];
        
        if (  p > max ||
            ( p < max && p > min ) ) {
            max = p;
            min = p;
        }
        
        else if ( p < min ) {
            min = p;
            
            if ( maxdd < max - min) {
                maxdd = max - min;
            }
        }
    }
    
    cout << "maxdd = " << maxdd << endl;
    
    return 0;
}