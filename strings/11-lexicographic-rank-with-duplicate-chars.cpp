// find the lexicographic rank of the string with characters repeating


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void factorial(vector<long long> &fact)
{
    int n=fact.size();
    fact[0] = 1;
    for(int i=1;i<n;i++)
        fact[i] = fact[i-1]*i;


}

long long lexRank(string &s)
{
    int n = s.length();
    vector<long long> fact(n, 0);
    factorial(fact);
    int characters[256] = {0};
    int charCount[256] = {0};
    long long rank = 1;


    for(int i=0;i<n;i++)
    {
        characters[s[i]]++;
        charCount[s[i]]++;
    }
    for(int i=1;i<256;i++)
        characters[i] +=characters[i-1];

    long long repeatFact ;
    for(int i=0;i<n-1;i++)
    {   
        repeatFact = 1;
        bool visited[256] = {false};
        for(int k = i; k<n;k++)
        {
            if(!visited[s[k]] && charCount[s[k]]>1)
            {
                repeatFact *= fact[charCount[s[k]]];
                visited[s[k]] = true;
            }
        }
        
        rank += (fact[n-i-1]*characters[s[i]-1])/repeatFact;
        charCount[s[i]]--;
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