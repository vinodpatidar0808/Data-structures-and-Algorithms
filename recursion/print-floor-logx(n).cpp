// print floor of logx(n)

#include <iostream>

using namespace std; 

int  floor_log(int x, int n)
{
    if(n<x)
        return 0;
    return 1 + floor_log(x, n/x);
}

int main()
{
    int base, number;
    cin>>base>>number;
    cout<<"floor of log "<<number<<" to the base "<<base<<": "<<floor_log(base,number);
    return 0;
}