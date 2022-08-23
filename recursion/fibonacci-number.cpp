// problem: calculate nth fibonacci number.
// fibonacci numbers : 0,1,1,2,3,5,8,13,21,34....
// f(n) = f(n-1) + f(n-2)



#include <iostream>

using namespace std; 

int fibonacci(int n)
{
    if(n==1)
        return 0;
    else if(n == 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);

}

int main()
{
    int n ;  // n>0 , I am considering first fibonacci number as 0, 2nd as 1, 3rd as 1 ...
    cin>>n;
    cout<<n<<"th fibonacci number is: "<<fibonacci(n);       
    return 0;
}