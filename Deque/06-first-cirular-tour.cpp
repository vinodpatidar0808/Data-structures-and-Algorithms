// n petrol pumps arranged in a circular manner represented using 2 arrays, 1st array represents amount of petrol and 2nd array represents distance of next petrol pump from this petrol pump.
// task: choose first petrol pump such that we can visit all petrol pumps and come back to this pump again.

#include <iostream>

using namespace std; 

// we will return position of petrol pump not index
// time comp : O(n^2)
int firstPetrolPump(int petrol[], int distance[], int n)
{
    int currPetrol = 0;
    int j;
    for(int i = 0; i < n; i++)
    {
        currPetrol = 0;
        j = i;
        while(true)
        {
            currPetrol += (petrol[j] -distance[j]);
            if(currPetrol<0)
                break;
            // circular tour
            j  = (j + 1)%n;
            if(j== i)
                return i+1; // position is i+1
        }
    }
    return -1;
}

// time comp : O(n) 
int firstPump(int petrol[], int distance[], int n)
{
    int startPos = 0;
    int currPetrol =0;
    int extraPetrolNeeded = 0;
    for(int i=0;i<n;i++)
    {
        currPetrol += (petrol[i] - distance[i]);
        if(currPetrol < 0)
        {
            startPos = i+1;
            extraPetrolNeeded += currPetrol;
            currPetrol = 0;
        }
    }
    return (currPetrol+extraPetrolNeeded >= 0 ? startPos+1: -1);
}

int main()
{
    // int petrol[] = {50,20,60,80};
    int petrol[] = {50,20,60,80};
    int distance[] = {30,10,40,100};
    int n= sizeof(petrol)/sizeof(petrol[0]);
    int res = firstPetrolPump(petrol, distance, n);
    int res2 = firstPump(petrol, distance, n);
    cout<<res<<endl;
    cout<<res2<<endl;


    return 0;
}