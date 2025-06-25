#include <iostream>
#include "CMyVektor.h"
#include "Functions.h"

int main() {
    CMyVektor stelle1(2);
    stelle1[0] = 0.2;
    stelle1[1] = -2.1;
    CMyVektor result = gradientenverfahren(f,stelle1);
    std::cout << result[0] << " " << result[1];
}