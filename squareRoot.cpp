# finding-the-square-root-in-logn
#include <iostream>

using namespace std;

long long int squareRoot(int n)
{
    int start = 0 ;
    int end = n ;
    long long int ans = -1 ;
    long long mid = start + (end-start)/2 ;
    while(start <= end)
    {
        long long square = mid * mid ;
        if(square == n)
        {
            return mid ;
        }
        else if(square < n)
        {
            ans = mid ;
           start = mid+1 ;
        }
        else
        {
            end = mid-1 ;
        }
        mid = start + (end - start)/2 ;
    }
    return ans ;
}

double morePrecision(int number , int precision , int tempSol )
{
    double factor = 1 ;
    double ans = tempSol ;
    for(int i = 0 ; i < precision ; i++)
    {
        factor = factor/10 ;
        for(double j = ans ; j*j <number ; j = j+factor)
        {
            ans = j ;
        }
    }
    return ans ;
}

int main()
{
    int ans = squareRoot(37) ;
    cout << ans << endl ;
    double precision = morePrecision(37 , 3 , ans) ;
    cout << "The square root of " << ans << " is " << precision ;

    return 0;
}
