#include "barrier.h"
#include "BSModel.h"

#include <iostream>
using namespace std;

int main(){
    double S0 = 100.0, r = 0.05, sigma = 0.2;
    BSModel model(S0, r, sigma);
    
    double T  = 1.0, K = 100.0, B = 150.0;
    int m = 100;
    int type = 0; // 0 : up and out, 1 : up and in 

    barrierOption barrier(type, m, T, K, B);

    int n_sims = 3000;
    cout << "Up and out barrier option price: "
        << barrier.priceByMC(model,n_sims)
        << endl;

    return 0;
}
