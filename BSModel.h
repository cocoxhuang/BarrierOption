#ifndef BSModel_h
#define BSModel_h

#include <time.h>
#include <stdlib.h>     /* srand, rand */

using namespace std;
#include <vector>
typedef vector<double> samplePath;

class BSModel
{
    public:
        double S0, r, sigma;
        BSModel(double S0_, double r_, double sigma_){S0 = S0_; r = r_; sigma = sigma_;srand(time(NULL));}
        void generateSamplePath(double T, int m, samplePath& S);
};

#endif