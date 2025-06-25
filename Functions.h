#pragma once
#include "CMyVektor.h"
#include <math.h>


CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x))
{
    double h = 1e-8;
    double zwischen;
    CMyVektor grad = CMyVektor(x.get_dimension());
    double wert = funktion(x);
    for(unsigned int i = 0;i<x.get_dimension();i++)
    {
        zwischen = x[i];
        x[i] = x[i]+h;
        grad[i]= (funktion(x) - wert)/h;
        x[i]=zwischen;
    }
    return grad;
}

CMyVektor gradientenverfahren(double (*funktion)(CMyVektor x), CMyVektor start, double lambda = 1)
{
    CMyVektor grad = gradient(start,funktion);
    double currentValue;
    double newValue;
    for(int i = 0; i < 25 && grad.laenge()>=0.00001; i++)
    {
        currentValue = funktion(start);
        newValue = funktion(start+(lambda * grad));
        if(currentValue < newValue)
        {
            currentValue = newValue;
            newValue = funktion(start+(2*lambda*grad));
            if(currentValue < newValue)
            {
                lambda = lambda*2;
                currentValue = newValue;
            }
            start = start + (lambda * grad);
        }
        else
        {
            do
            {
                lambda = lambda/2;
                newValue = funktion(start+(lambda * grad));
            } while(currentValue >= newValue);
            start = start + (lambda * grad);
            currentValue = newValue;
        }
        grad = gradient(start,funktion);
    }
    return start;
}

double f(CMyVektor x)
{
    return sin(x[0]*x[1]) + sin(x[0]) + cos(x[1]);
}

CMyVektor c(CMyVektor x)
{
    if(x.get_dimension() != 2)
        throw "Unpassende Dimension fuer c";
    CMyVektor result(2);
    result[0] = x[0]*x[0]*x[0]*x[1]*x[1]*x[1]-2*x[1];
    result[1] = x[0]-2;
    return result;
}

double g(CMyVektor x)
{
    return -(2*x[0]*x[0]-2*x[0]*x[1]+x[1]*x[1]+x[2]*x[2]-2*x[0]-4*x[2]);
}
