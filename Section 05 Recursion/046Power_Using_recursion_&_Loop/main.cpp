#include <iostream>

using namespace std;

int loopPowerFuncNOTWORK(int num_base, int num_exp)
{
    int m = num_base, i = num_exp;
    int answer=1;

    while(i>0)
    {
//        if(i==0 or i==1) //reached end of iteration.
//         break;
        if(i==1)
            break;

        if(i%2 != 0 ) // exponent is odd.
            {m*=num_base;
                i/=2;
//                break;
            }

        else //if(i%2==0) // num_exp is even. we can divide 2^8  as ( 2 * 2 )^(8/2).
        {
            m*=m ;
//            answer*= num_base*num_base;
            i/=2;
        }
//        else // i is odd.
//        {
//            m*=num_base;
//            answer*= num_base* num_base * num_base;
//            i =(i-1)/2;
//        }

    }

    return m;
//    return answer;

}

int recurPowerFunc(int num_base, int num_exp)
{
    if(num_exp ==0)
        return 1;
    else if(num_exp%2 == 0)
        return recurPowerFunc(num_base*num_base,num_exp/2);
    else
        return num_base * recurPowerFunc(num_base*num_base , (num_exp-1)/2 );
}

//Souce: https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
int loopPowerFunc(int num_base, int num_exp)
{
    int result = 1;
    while(num_exp>0)
    {
        if(num_exp%2 != 0)
            result*= num_base;

        num_exp/=2;
        num_base*= num_base;
    }

    return result;
}

int main()
{
    cout << "loopPowerFunc 2^5: " << loopPowerFunc(2,5) << endl;
//    cout << "loopPowerFunc 2^9: " << loopPowerFunc(2,9) << endl;
//    cout << "loopPowerFunc 2^4: " << loopPowerFunc(2,4) << endl;
//    cout << "loopPowerFunc 2^3: " << loopPowerFunc(2,3) << endl;

//    cout << "recurPowerFunc 2^4: " << recurPowerFunc(2,4) << endl;

    return 0;
}
