// problem : print all divisors of a number in sorted order
#include <iostream>

using namespace std; 

// simplest O(n)
void divisors(int n)
{
    cout<<"Divisors of "<<n<<" are: ";
    for(int i=1;i<=n;i++)
        if(n%i==0)
            cout<<i<<", ";
    cout<<endl;
}

// divisors always appear in pairs and one divisor will always be less than or equal to sqrt(number)
// does not print in sorted order 
// time complexity O(sqrt(n))
void divisors_2(int n)
{
    for(int i=1; i*i<=n;i++)
    {
        if(n%i == 0)
        {
            cout<<i<<", ";
            if(i != n/i)
                cout<<n/i<<", ";
        }    
    }
    cout<<endl;
}

// time complexity O(sqrt(n))
void divisors_sorted(int n)
{
    int i ;
    for(i = 1 ; i*i<n ; i++)
        if(n%i == 0)
            cout<<i<<", ";
    // cout<<" ---loop change--- i is "<<i<<", ";
    for( ; i>=1 ; i--)
        if(n%i==0 && n/i>i)
            cout<<n/i<<", ";
}

int main()
{
    int n ;
    cin>> n;
    divisors(n);
    divisors_2(n);
    divisors_sorted(n);
    return 0;
}