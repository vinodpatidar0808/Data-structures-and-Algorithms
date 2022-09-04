// Given number of pages in n books. 
// k students are required to read the books. One student can only read contiguous books.
// minimize the maximum pages allocated to a student. Only contiguous pages can be allocated.
// a student have to read all pages of allocated books.

#include <iostream>
#include <limits>
#include <algorithm>

using namespace std; 

int sumArray(int arr[], int l, int r)
{
    int sum = 0;
    while(l<=r)
        sum+=arr[l++];
    return sum;
}

// we make n-1 cuts and we have to select k-1 cuts such that it minimizes the number of pages.
// this has exponential time complexity : trying every possible solution
int minPages(int pages[], int  n, int k)
{   
    // if only one student -> have to read all books.
    if(k==1)
        return sumArray(pages,0,n-1);
    if(n==1)
        return pages[0];
    int res = INT_MAX;
    for(int i=1;i<n;i++)
    {
        res = min(res, max(minPages(pages, i, k-1), sumArray(pages, i, n-1)));
    }
    return res;
}


int isPossible(int arr[], int n, int k, int sum)
{
    int reqStudents {1};
    int currSum {0};
    for(int i=0;i<n;i++)
    {
        if(currSum+arr[i] > sum)
        {
            reqStudents++;
            currSum = arr[i];
        }
        else
            currSum += arr[i];
    }
    return (reqStudents <= k);
}

// using binary search: array not sorted but a special problem
int countMinPages(int arr[],int n, int k)
{
    int sum {0};
    int maxPages {0};
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxPages = max(maxPages, arr[i]);
    }

    int l {maxPages}, h {sum}, res  {0};
    int mid ;
    
    while(l<=h)
    {
        mid = l + (h-l)/2;
        if(isPossible(arr,n,k,mid))
        {
            res = mid;
            h = mid-1;
        }    
        else
            l = mid+1;
    }
    return res;

}


int main()
{
    int n ;
    cout<<"Enter number of books"<<endl;
    cin>>n;
    int pages[n];
    int i=0;
    cout<<"Enter pages in all "<<n<<" books "<<endl;
    while(i<n)
    {
        cin>>pages[i++];
    }

    int k ;
    cout<<"Enter number of students."<<endl;
    cin>>k;
    cout<<endl;
    // int res = minPages(pages, n, k);
    int res = countMinPages(pages, n,k);
    cout<<"maximum pages "<<res<<endl<<endl;

    return 0;
}


