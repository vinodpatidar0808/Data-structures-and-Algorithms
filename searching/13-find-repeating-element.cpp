// Given an array with only one element repeating any number of times. find the number.

/**
 * rules:
 *  Array size>=2
 *  only one element repeats( any number of times)
 * all the elements from 0 to max(arr) are present  =>   0 <= max(arr) <= n-2
 * 
 * try to solve in O(n) time and O(1) space.
 */ 

// this problem can be solve in many ways, some of them don't satisfy the given conditions

// solution 1: running 2 loops O(n^2)
// solution 2: sorting and then looking for the repeating element , O(nlog(n))
// solution 3: create a boolean array and of size n, using array elements as indices. or using hashing(sets or maps)


#include <iostream>

using namespace std; 

// using boolean array O(n) time and O(n) space
int findRepeating(int arr[], int n)
{
    bool visited[n] {0} ;
    for(int i=0;i<n;i++)
    {
        if(visited[arr[i]])
            return arr[i];
        visited[arr[i]] = 1;
    }
    return 0; 
}

// O(n) time and O(1) space 
// when elements are in range 1 to max(arr)
// Traverse array linearly & use array elements as indices & form a chain when element repeats there will be a cycle in the chain.
int repeatingOneToMax(int arr[], int n)
{
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    slow = arr[0];
    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}


// why we add 1 to slow and fast --> take example of this arr [1,0,2,2,2] -> here neither 1 or 0 repeats. If we don't add 1 to slow and fast they will form a cycle.

int repeatingZeroToMax(int arr[], int n)
{
    int slow {arr[0]+1};
    int fast {arr[0]+1};
    do
    {
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    } while (slow != fast);
    
    slow = arr[0]+1;
    while(slow != fast)
    {
        fast = arr[fast]+1;
        slow = arr[slow]+1;
    }
    return slow - 1;
}

int main()
{
    int n ; 
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    int i=0;
    bool arrayContainsZero = false;
    while(i<n)
    {
        cin>>arr[i];
        if(arr[i] == 0)
            arrayContainsZero = true;
        i++;
    }

    // int res = findRepeating(arr, n);
    int res;
    if(!arrayContainsZero)
        res = repeatingOneToMax(arr, n);
    else
        res = repeatingZeroToMax(arr, n);

    cout<<"Repeating element is "<<res<<endl;
    
    return 0;
}