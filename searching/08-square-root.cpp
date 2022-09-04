// Find the floor of the square root of a number 
#include <iostream>

using namespace std; 

// time comp: O(sqrt(n))
int squareRoot(int n)
{
    int i= 1;
    while(i*i<n)
    {
        i++;
    }

    return i-1;
}


// using binary search
int sqRoot(int n)
{
    int l = 1;
    int r = n;
    int ans = -1;
    int mid;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        int square = mid*mid;
        if( square == n)
            return square;
        else if(square > n)
            r = mid-1;
        else 
        {
            ans = mid ;
            l = mid+1;
        }
    }
    return ans;
}

int main()
{
    int n ;
    cout<<"Enter number to get it's square root:"<<endl;
    cin>>n;
    int sqroot = squareRoot(n);
    cout<<"Floor of square root of "<<n<<" is "<<sqroot<<endl;
    cout<<"Floor of square root of "<<n<<" is "<<sqRoot(n)<<endl;
    
    return 0;
}