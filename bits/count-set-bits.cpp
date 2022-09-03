#include <iostream>

using namespace std; 


// time comp: O(total bits in binary representation)
int countSetBits(int n)
{
    int  setBits = 0;
    string binary {""};
    while(n>0)
    {
        // to check if last bit is set or unset, odd numbers have last bit as set and even have last bit as 0
        if(n & 1==1)
        {
            setBits++;
            binary = '1'+binary;
        }
        else
            binary = '0'+binary;
        // removing last bit n/2==(n>>1)
        n=n/2;
    }
    cout<<binary<<endl;
    return setBits;
}


// time comp: O(total set bits in binary representation)
// Brian kerningam's algorithm
// n-1 ==> zeroes after rightmost set bits becomes 1 & and 1 of rightmost set bit becomes 0
int setBits(int n)
{
    int res = 0;
    while(n)
    {
        n = n & (n-1);
        res++;
    }
    return res;
}

int main()
{
    int n ;
    cin>>n;
    int res = countSetBits(n);
    cout<<"Set bits in "<<n<<" = "<<res<<endl;
    cout<<"Set bits in "<<n<<" = "<<setBits(n)<<endl;
    return 0;
}