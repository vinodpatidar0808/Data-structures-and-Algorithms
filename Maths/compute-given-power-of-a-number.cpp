// problem : compute x^n 

#include <iostream>

using namespace std; 

// time complexity ; O(exponent)
int power(int base, int exp)
{
    int ans = 1;
    for(int i=1;i<=exp;i++)
    {
        ans = ans*base;
    }
    return ans;
}

// x^n = x^(n/2) * x^(n/2)  if n is even
// x^n = x^(n-1)*x => x^((n-1)/2) * x^((n-1)/2)  if n is odd

// time complexity: O(log(n)), aux space O(log(n))
int power_rec(int base, int exp)
{
    if (exp == 0)
        return 1;
    int temp = power_rec(base, exp/2);
    temp = temp*temp;
    if(exp%2 == 0)
        return temp;
    else    
        return base*temp;
}

// time comp: O(log(n)), aux space: O(1)
int power_iterative(int base, int exp)
{
    int ans = 1;
    while(exp>0)
    {
        if(exp%2 !=0)
            ans = ans* base;
        base = base*base;
        exp = exp/2;
    }
    return ans;
}

int main()
{
    int x, n;
    cin>>x>>n;
    cout<<x<<" raise to the power "<<n<<" = "<<power(x,n)<<endl;
    cout<<x<<" raise to the power "<<n<<" = "<<power_rec(x,n)<<endl;
    cout<<x<<" raise to the power "<<n<<" = "<<power_iterative(x,n)<<endl;


    return 0;
}