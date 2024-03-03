#include "barrier.h"
#include <cmath>
#include <iostream>

using namespace std;

double barrierOption::payOff(const samplePath& S){
    double res = 0;
    bool valid;
    if (type == 0){             // up and out
        valid = true;
    }       
    if (type == 1){             // up and in
        valid = false;
    }   

    for (int i = 0; i <= m; i++){
        if (S[i] > B){
            if (type == 0){             // up and out
                valid = false;
                break;
            }       
            if (type == 1){             // up and in
                valid = true;
                break;
            }       
        }
    }    
    if (valid == true){return max(S[m] - K,0.0);}else{return 0;}
}

double barrierOption::priceByMC(BSModel model, int n_sims){
    samplePath path(m+1);
    double price = 0;
    for(int k = 0; k < n_sims; k++){
        model.generateSamplePath(T,m,path);
        price = price + exp(-model.r * T) * payOff(path);
    }
    return price/n_sims;
}