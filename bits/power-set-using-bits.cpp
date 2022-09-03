#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std; 

// every character has 2 choice either include it or discard it.
// for a string of length n number of powersets = 2^n

// time comp: O(n*2^n)
void printPowerSet(string s)
{
    string curr;
    int n = s.size();
    int powerSetSize = pow(2,n);
    for(int i=0;i<powerSetSize;i++)
    {
        curr = "";
        for(int j=0;j<n;j++)
        {
            if( (i & (1<<j)) != 0 )
                cout<<s[j];
        }
        cout<<endl;
    }

}



int main()
{
    string str;
    cout<<"Enter a string: "<<endl;
    cin>>str;
    printPowerSet(str);    
    return 0;
}