#include <iostream>

using namespace std; 

// time comp: O(n)
int findXor(int x)
{
    int xvalue= 0;
    for(int i=1;i<=x;i++)
        xvalue^=i;
    return xvalue;
}

/**
 * if you do xor till  a certain number you will notice a pattern 
 * N%4==0 => N
 * N%4==1 => 1
 * N%4==2 => N+1
 * N%4==3 => 0
 */

int xorValue(int n)
{
    if(n%4 == 0)
        return n;
    if(n%4==1)
        return 1;
    if(n%4==2)
        return n+1;
    return 0;
}

int main()
{
    int n;

    cin>>n;
    cout<<findXor(n)<<endl;
    cout<<xorValue(n)<<endl;
    return 0;
}