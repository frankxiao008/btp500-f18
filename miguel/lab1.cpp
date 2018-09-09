unsigned int factorial (unsigned int n){
    int result=0;
    for(int i=n; i>=1; --i) {
        result *= n;
    }
    return result;
}

double power (double base, unsigned int n){
    int result = 0;
    for(int i=0; i<n; ++i) {
        result *= n;
    }
    return result;
}

unsigned int fibonacci (unsigned int n){
    int Fib=1;
    int FibPrev=0;
    int result=0;
    for(int i=0; i<n; ++i) {
        result = Fib+FibPrev;
        FibPrev = Fib;
        Fib = result; 
    }
    return result;
}
