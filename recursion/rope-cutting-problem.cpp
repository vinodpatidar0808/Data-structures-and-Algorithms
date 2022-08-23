// problem : given a rope of length l, cut these rope in maximum pieces such that each piece have length among a, b, c.



#include <iostream>
#include <algorithm>

using namespace std; 


// time complexity: O(3^n)
// can be improved using dynamic programming
int cutRope(int l, int a, int b, int c)
{
    // one possible cut found
    if(l == 0)
        return 0;
    if(l < 0)
        return -1;
    int res = max({cutRope(l-a,a,b,c),cutRope(l-b,a,b,c),cutRope(l-c,a,b,c)});

    if(res == -1)
        return -1;
    return res + 1;
}


int main()
{
    int l, a, b, c;
    cin>>l>>a>>b>>c;
    cout<<cutRope(l,a,b,c);
    return 0;
}