// Problem: count the number of trailing 0's in factorial of a number n

// Inefficient approach: calculate factorial and count trailing zeroes



#include <iostream>

using namespace std; 

int main()
{
    int n, res=0 ;
    cin>>n; // n>=0 for factorial
    for(int i=5; i<=n; i=i*5){
        res+= n/i; // n/i returns floor of n divided by 5
    }
    cout<<"No of trailing zeroes in factorial of "<<n<<" is "<<res<<endl;
    return 0;
}

// time complexity --> O(log(n)) 
/*
    i = 5, 5^2, 5^3, 5^4...... 5^k
    5^k = n -> take log5 on both side and you will have number of iterations

*/