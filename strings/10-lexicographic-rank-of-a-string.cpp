// lexicographic rank of the string with all distinct characters counting starts from 1
/**
 * eg. cba lexicographic rank of cba : 6
 * abc -> 1
 * acb -> 2
 * bac -> 3
 * bca -> 4
 * cab -> 5
 * cba -> 6
*/


#include <iostream>
#include <string>

using namespace std;

long long int factorial(int n)
{
    if(n<=1)
        return 1;
    long long fact = 1;
    for(int i=1;i<=n;i++)
        fact = fact*i;
    return fact;
}

int lexRank(string &s)
{
    int n = s.length();
    int lenFact = factorial(n);
    int characters[256] = {0};
    int rank = 1;

    for(int i=0;i<n;i++)
        characters[s[i]]++;
    for(int i=1;i<256;i++)
        characters[i] +=characters[i-1];


    for(int i=0;i<n-1;i++)
    {
        lenFact = lenFact/(n-i);
        rank += (lenFact*characters[s[i]-1]);

        for(int j=s[i];j<256;j++)
            characters[j]--;

    }
    return rank;
    
}


int main()
{
    string s;
    cout<<"enter string: "<<endl;
    cin>>s;
    cout<<"Lexicographic rank of string '"<<s<<"' is "<<lexRank(s)<<endl;
    return 0;
}