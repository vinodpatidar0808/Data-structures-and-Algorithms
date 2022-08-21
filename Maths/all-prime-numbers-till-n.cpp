// problem: all prime numbers from 1 to given number n

#include <iostream>
#include <vector>

using namespace std; 


// time complexity : O(n*sqrt(n))
/*
void allPrimes(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(isPrime(i))  // O(sqrt(n))
            cout<<i<<", ";
    }
}
*/

// all primes using sieve algorithm
// time complexity O(n*log(log(n)))
void allPrimesSieve(int n)
{
    vector <bool> isPrime(n+1, true);

    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            cout<<i<<", ";
            for(int j=i*i; j<=n;j=j+i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    allPrimesSieve(n);
    return 0;
}