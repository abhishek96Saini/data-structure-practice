#include <stdio.h>
#include <stdlib.h>

/*
e^x= 1 + x/1 + x*x/2! + x*x*x/3! + ....... (n) terms
integer x = the value of power in e^x
integer n = number of terms ... the "n" terms.

start from number of terms = 'n' till it reaches down to 0.
static double variables "power" and "factorial" are used to compute the values of the successive (x^n / n!) ratio in Taylor series.
*/
double TaylorSeries(int x, int n)
{
    static double power = 1 , factorial = 1;
    double computeResult;

    if(n==0) // the first term of Taylor series is 1.
        return 1;
    computeResult = TaylorSeries(x,n-1);  //Calculate the previous terms sum and then proceed to next term computation.
    power = power * x;
    factorial = factorial * n;
    // Now we need to find the power/factorial or  x^n/n!  of the current term that is going to be computed, and then
    // add this new ratio with the previously calculated computeResult.

    return (computeResult + (power/factorial) );


}
int main()
{
    printf("%lf",TaylorSeries(1,15));

    return 0;
}
