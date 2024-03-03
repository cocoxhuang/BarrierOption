#include "BSModel.h"
#include <cmath>

#include <iostream>

using namespace std;

double sampleNormal(){
    /*
    Using Box-Muller transform: 
    Z = sqrt(-2*ln(U1)) * cos(2*pi*U2)
    where U1, U2 are uniform on [0,1].
    */
   double U1 = (rand() + 1.0)/(RAND_MAX+1.0);
   double U2 = (rand() + 1.0)/(RAND_MAX+1.0);
   return sqrt(-2 * log(U1)) * cos(2 * M_PI * U2);
}

void BSModel::generateSamplePath(double T, int m, samplePath& S){
    double St = S0;
    S[0] = S0;
    for (int i = 1; i <= m; i++){
        S[i] = St * exp((r - sigma * sigma * 0.5)*(T/m) + sampleNormal() * sigma * sqrt(T/m));
        St = S[i];
    }
}
