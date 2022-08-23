// Problem: 

#include <iostream>

using namespace std; 

// when numbering is 0 to n-1
// time compl : O(n)
int josephus(int n, int k)
{
    if(n==1)
        return 0;
    return (josephus(n-1,k)+k)%n;
}

// when numbering is  1 to n
int josephus_2(int n, int k)
{
    if(n==1)
        return 1;
    return (josephus_2(n-1,k)+ k-1)%n + 1;
}


int main()
{
    int n, k;
    cin>>n>>k;
    cout<<josephus(n, k)<<endl;
    cout<<josephus_2(n, k);
    return 0;
}