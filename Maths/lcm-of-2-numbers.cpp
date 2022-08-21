#include <iostream>

using namespace std; 

// time complexity O(a*b - max(a,b))
int lcm_inefficient(int x, int y){
    int lcm = max(x,y);
    while(true)
    {
        if(lcm%x ==0 && lcm%y == 0)
            return lcm;
        lcm++;
    }
    return lcm;
}

// lcm(x,y) * hcf(x,y) = a*b
// calculate hcf using euclidean and get lcm efficiently

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<"lcm of "<<x<<" and "<<y<<" is "<<lcm_inefficient(x,y)<<endl;
    return 0;
}