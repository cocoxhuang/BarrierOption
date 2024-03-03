#ifndef barrier_h
#define barrier_h

#include "BSModel.h"

class barrierOption{
    /*
    int type : 
        0 : up and out
        1 : up and in
    double T : time to maturity;
    double K : strke price;
    double B : barrier price;
    int m: number of steps to maturity;
    */
    public:
        double T,K,B;         //
        int type, m;     
        barrierOption(int type_, double m_,double T_, double K_, double B_){type = type_; m = m_; T = T_; K = K_; B= B_;}
        double priceByMC(BSModel model, int n_sims);
        double payOff(const samplePath& S);
};

#endif