// problem : given a number print it's binary representation
#include <iostream>

using namespace std; 

void print_binary(int n)
{
    if(n==0)
        return;
    print_binary(n/2);
    cout<<n%2;
}

int main()
{
    int n;
    cin>>n;
    print_binary(n);    
    return 0;
}