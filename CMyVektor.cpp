#include "CMyVektor.h"
#include <math.h>
#include <assert.h>

CMyVektor::CMyVektor() : dimension(3)
{
    v.resize(3);
    v[0]=0;
    v[1]=0;
    v[2]=0;
}

CMyVektor::CMyVektor(unsigned int dimension) : dimension(dimension)
{
    v.resize(dimension);
    for(unsigned int i = 0; i<dimension;i++)
            v[i]=0;
}

double CMyVektor::laenge()
{
    double laenge = 0;
    for(unsigned int i = 0; i<dimension;i++)
        laenge += v[i]*v[i];
    return sqrt(laenge);
}

CMyVektor CMyVektor::operator+(CMyVektor a)
{
    if(dimension != a.dimension);
    CMyVektor neu = CMyVektor(dimension);
    for(unsigned int i = 0;i<dimension;i++)
    {
        neu[i]= v[i] + a[i];
    }
    return neu;
}

CMyVektor operator*(double lambda, CMyVektor a)
{
    CMyVektor neu = CMyVektor(a.get_dimension());
    for(unsigned int i = 0; i<a.get_dimension();i++)
        neu[i] = a[i]*lambda;
    return neu;
}
