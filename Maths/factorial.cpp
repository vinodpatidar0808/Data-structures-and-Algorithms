#include <iostream>

using namespace std; 

int factorial(int n){
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

int main()
{
    int n ;
    int res = 1;
    cin>> n; // n>=0
    for(int i=2;i<=n;i++){
        res=res*i;
    }
    cout<<res<<endl;
    int rec_res=factorial(n);
    cout<<rec_res<<endl;
    
    return 0;
}
