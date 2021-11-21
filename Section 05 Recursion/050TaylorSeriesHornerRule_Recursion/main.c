#include <stdio.h>
#include <stdlib.h>

/*
e^x= 1 + x/1 + x*x/2! + x*x*x/3! + ....... (n) terms
integer x = the value of power in e^x
integer n = number of terms ... the "n" terms.

Using Horner rule
e^x = 1 + (x\1)*[1+(x/2)*[1 + (x/3) * [1 + (x/4) * [.... n terms] ] ] ]         -------equation (1)

Therefore,  the smallest term to compute is 1 + (x/n). We'll call this smallest term as computedSum.
computedSum is a static double variable used to store 1 + x/n .... that will store from n to 0.

start from number of terms = 'n' till it reaches down to 0.
static double "computedSum" is used to store the successive atomic term multiplied with previous result sum.
*/

double TaylorSeries_Horner(int x,int n)
{
    static double computedSum = 1; // minimum value of e^x can be 1.

    if(n==0) // We have reached end of the Taylor series. All the bracketed terms have been calculated. Refer to equation (1) on line number 10.
        return computedSum;
    //else

    //typecast integer values 'x' and 'n'.
    computedSum = 1 +   ((double)x/n)* computedSum; // 1 + x/n* [ the bracketed terms. Calculated previously and stored in computedSum] . Refer equation (1) for understanding.
    return TaylorSeries_Horner(x,n-1);
}

int main()
{

    printf("%f", TaylorSeries_Horner(1,10));
    return 0;
}
