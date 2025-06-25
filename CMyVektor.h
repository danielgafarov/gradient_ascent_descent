#pragma once
#include <vector>

class CMyVektor
{
    private:
        std::vector<double> v;
        unsigned int dimension;
    public:
    CMyVektor();
    CMyVektor(unsigned int dimension);
    unsigned int get_dimension(){return dimension;}
    double& operator[] (unsigned int index){return v[index];}
    double laenge();
    CMyVektor operator+(CMyVektor a);
    bool operator>(CMyVektor a);
}; 

CMyVektor operator*(double lambda, CMyVektor a);