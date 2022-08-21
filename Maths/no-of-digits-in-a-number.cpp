// problem : find the number of digits in a given number n ?

// one liner : no of digits in any number n is always  = floor(log10(n) + 1);

#include <iostream>

using namespace std; 

// iterative function to count no of digits in n
// time complexity : O(no of digits)
int digitsIterative(int n){
    int res =0;
    while(n!=0){
        n = n/10;
        res++;
    }
    return res;
}

// recursive function to count no of digits in n
int digitsRecursive(int n){
    if(n==0)
        return 0;
    return 1+digitsRecursive(n/10);
}

int main()
{
    int n, digits_iteratve, digits_recursive ;
    cin>>n;
    digits_iteratve = digitsIterative(n);
    digits_recursive = digitsRecursive(n);
    cout<<"no of digits in "<<n<<" is "<<digits_iteratve<<endl;
    cout<<"no of digits in "<<n<<" is "<<digits_recursive<<endl;
    
    
    return 0;
}