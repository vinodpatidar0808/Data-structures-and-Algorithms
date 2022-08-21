// get all prime factors of a given number

#include <iostream>

using namespace std; 

// easiest : 
/*
    void prime_factors(int n){
        for(int i=2; i<n; i++)
        {
            if(isPrime(i)){
                int x = i;
                while(n%x==0)
                {
                    cout<< i ;
                    x = x*i;
                }
            }
        }
    }
*/

// a number can be written as multiplication of powers of prime numbers --> factorization

void prime_factors(int n){
    if(n<=1)
        return;
    cout<<"prime factors of "<<n<< " are: ";
    for(int i=2;i*i<n;i++)
    {
        while(n%i==0)
        {
            cout<< i <<", ";
            n = n/i;
        }
    }
    if(n>1)
        cout<<n;
}

void prime_factors_2(int n)
{
    cout<<"prime factors of "<<n<< " are: ";
    if(n <= 1)
        return;
    
    while(n%2 == 0)
    {
        cout<<2<<", ";
        n = n/2;
    }
    while(n%3 == 0)
    {
        cout<<3<<", ";
        n = n/3;
    }

    // divisors appear in pairs and prime numbers except 2 and 3 can be written as (6*n - 1) or (6*n + 1)
    for(int i=6;i*i<=n;i=i+6)
    {
        while(n%(i-1) == 0)
        {
            cout<<i-1<<", ";
            n = n/(i-1);
        }
        while(n%(i+1) == 0)
        {
            cout<<i+1<<", ";
            n = n/(i+1);
        }
    }
    if (n>3)
        cout<<n;
}

int main()
{
    int n ;
    cin>>n;
    // prime_factors(n);
    prime_factors_2(n);

    return 0;
}