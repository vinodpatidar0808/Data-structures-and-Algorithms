// Problem : Given 2 numbers X and Y find HCF(highest common factor)/GCD(greatest common divisor) of x and y

#include <iostream>

using namespace std; 

// time complexity O(min(x,y))
int gcd_1(int x, int y){
    int res = min(x,y);
    while(res>0)
    {
        if(x%res==0 && y%res==0)
            break;
        res--;
    }
    return res;
}

// using Euclidean algorithm 
// time complexity : O(log(min(x, y)).
int euclidean_basic(int x, int y){
    while(x != y)
    {
        if(x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

// euclidean optimized 
int euclidean(int x, int y)
{
    if(y==0)
        return x;
    return euclidean(y, x%y);
}

int main()
{
    int x, y; 
    cin>>x;
    cin>>y;
    int gcd = gcd_1(x, y);
    cout<<"gcd of "<<x<<" and "<<y<<" is "<<gcd<<endl;
    cout<<"gcd of "<<x<<" and "<<y<<" is "<<euclidean_basic(x,y)<<endl;
    cout<<"gcd of "<<x<<" and "<<y<<" is "<<euclidean(x,y)<<endl;
    return 0;
}