// find floor(log2(n))

#include <iostream>

using namespace std; 

int log2(int n)
{
    int res= 0;
    while(n>>=1)
    {
        res++;
    }
    return res;
}

int main()
{
    int n ;
    cin>>n;

    cout<<"Floor of log on base 2 of "<<n<<" is "<<log2(n)<<endl;
    return 0;
}