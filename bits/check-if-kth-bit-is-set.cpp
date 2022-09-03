// check if kth bit from right side in a number is set or not.

#include <iostream>

using namespace std; 

// shift 1 to kth bit
bool isSet(int n , int k)
{
    if((n & (1<<(k-1))) != 0)
        return true;
    return false;
}

// shift kth bit of number to last position
bool isSet2(int n, int k)
{
    if(n>>(k-1) & 1 ==1)
        return true;
    return false;
}

int main()
{
    
    int n,k;
    cin>>n>>k;
    cout<<boolalpha<<endl;
    cout<<isSet(n, k)<<endl;
    cout<<isSet2(n,k)<<endl;
    return 0;
}