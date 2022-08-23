// 3 Towers A (source), B (auxilliary), C (destinatio), discs are placed in tower src, we have to move  these discs to tower c and we have to use tower B in this. move discs in same order.
/*
    Rules: 
        1. Only one disc can moive at a time.
        2. No larger disc can be placed above a smaller disc.
        3. Only the top disc of a tower can be moved.

*/

#include <iostream>

using namespace std; 

// 2^n -1 movements for n discs
// time comp : O(2^n)
void moveDiscs(int n, char src, char aux, char dest)
{
    if(n == 1)
    {
        cout<<"Move disc 1 from "<<src<<" to "<<dest<<endl;
        return;
    }   
    
    moveDiscs(n-1,src, dest, aux);
    cout<<"Move disc "<<n<<" from "<<src<<" to "<<dest<<endl;
    moveDiscs(n-1,aux,src,dest);
}


int main()
{
    int n; // n is number of disc to move disc i is smaller than disc j (i < j)
    cin>>n; 
    char src='A', aux='B', dest='C';
    moveDiscs(n, src, aux, dest);
    return 0;

}