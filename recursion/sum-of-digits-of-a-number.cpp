// Problem : calculate the sum of digits of a given number


#include <iostream>

using namespace std; 

// n%10 --> gives last digit of a number, n/10 -> removes last digit from the number.
// time complexity : O(no of digits), aux space : O(no of digits)
int sum_digits(int n)
{
    if(n<10)
        return n;
    return n%10 + sum_digits(n/10);
}

// time comp: O(no of digits)
int sum_digits_iterative(int n)
{
    if(n<10)
        return n;
    int res = 0;
    while(n>0)
    {
        res = res+n%10;
        n = n/10;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    cout<<"sum of digits in number "<<n<<" is: "<<sum_digits(n)<<endl;    
    cout<<"sum of digits in number "<<n<<" is: "<<sum_digits_iterative(n);    
    return 0;
}