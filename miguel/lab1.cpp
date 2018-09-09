#include <stdio.h>
unsigned int factorial (unsigned int n){
    int result=1;
    for(int i=n; i>=1; --i) {
        result *= i;
    }
    return result;
}

double power (double base, unsigned int n){
    int result = 1;
    for(int i=0; i<n; ++i) {
        result *= base;
    }
    return result;
}

unsigned int fibonacci (unsigned int n){
    int FibPrevPrev=0;
    int FibPrev=1;
    int result=0;
    if(n==1) result=1;
    for(int i=1; i<n; ++i) {
        result = FibPrev+FibPrevPrev;
        FibPrevPrev = FibPrev;
        FibPrev = result;
    }
    return result;
}
