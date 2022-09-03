#include <iostream>

using namespace std; 

// time comp: O(total bits in n)
bool isPowerOf2(int n)
{
    if(n==0)
        return false;
    while(n!=1)
    {
        if(n &1 ==1)
            return false;
        n = n/2;
    }
    return true;
}

// time comp; O(1)
// any 2^x (x>0)  will have only 1 bit set which is msb. To unset rightmost bit n - 1
bool isPower2(int n)
{
    if(n ==0)
        return false;
    return !(n & (n-1));
}


int main()
{
    int n;
    cin>>n;

    cout<<boolalpha<<endl;
    cout<<"is "<<n<<" a power of 2: "<<isPowerOf2(n)<<endl;    
    cout<<"is "<<n<<" a power of 2: "<<isPower2(n)<<endl;    
    return 0;
}