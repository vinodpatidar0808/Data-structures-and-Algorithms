// problem: given a number x check if it is prime number or not 

#include <iostream>
#include <string>


using namespace std; 

// time complexity O(n)
bool is_prime(int x)
{
    if(x == 1)
        return false;
    for(int i=2;i<x;i++)
        if(x%i == 0)
            return false;
    return true;
}

// efficient : divisors of a number appear in pairs 
// time complexity O(sqrt(n))
bool is_prime_2(int n){
    if(n==1)
        return false;
    for (int i=2; i*i<=n ;i++)
        if(n%i == 0)
            return false;
    return true;
}

// more efficient : any prime number except 2 and 3 can be written in form of (6*n -1 ) or (6*n + 1)
// time complexity: O(sqrt(n)) but does lot less work then prev method. 
bool is_prime_3(int n)
{
    if (n == 1)
        return false;
    if(n == 2 || n==3)
        return true;
    if(n%2==0 || n%3==0)
        return false;
    
    for(int i=6; i*i <=n ;i=i+6)
    {
        if(n%(i-1)==0 || n%(i+1)==0)
            return false;
    }
    
    return true;   
}

int main()
{
    int x;
    cin>>x;
    string res ="";
    res = is_prime(x) == true?"a prime number.":"not a prime number.";
    cout<<x<<" is "<<res <<endl;
    
    res = is_prime_2(x) == true?"a prime number.":"not a prime number.";
    cout<<x<<" is "<<res <<endl;

    res = is_prime_3(x) == true?"a prime number.":"not a prime number.";
    cout<<x<<" is "<<res <<endl;

    
    return 0;
}