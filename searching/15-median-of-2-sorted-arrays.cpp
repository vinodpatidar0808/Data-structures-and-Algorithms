// find median of 2 sorted arrays

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std; 

void printArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void takeArrayInput(int arr[], int size)
{
    int i=0;
    while(i<size)
    {
        cin>>arr[i];
        i++;
    }
    cout<<endl;
}

// time comp : O((m+n)log(m+n))
float getMedian(int A[], int B[], int m, int n)
{
    int size = m + n;
    int temp[size];
    int ind=0;
    for(int i=0;i<m;i++)
    {
        temp[ind++]= A[i];
    }
    for(int j=0;j<n;j++)
    {
        temp[ind++]= B[j];
    }        

    sort(temp, temp+size);
    if(size%2==0)
        return (float)(temp[(size-1)/2]+temp[size/2])/2;
    return 
        temp[size/2];
}


// time comp: O(m+n)
// arrays are sorted, in combined array if number of elements are even then median would (arr[(size-1)/2]+arr[size/2])/2, if number of elements are odd then median = arr[size/2]

float getMed(int A[], int B[], int m, int n)
{
    int ind = -1; 
    int size = m+n;
    int i {0}, j {0};
    int curr, prev;
    while(i<m && j<n)
    {
        prev = curr;
        if(A[i]<=B[j])
        {
            curr = A[i++];
        }else{
            curr = B[j++];
        }
        ind++;
        if( ind == size/2 )
            break;
    }

    while(ind<size/2 && i<m)
    {
        ind++;
        prev = curr;
        curr = A[i++];
    }

    while(ind<size/2 && j<n)
    {
        ind++;
        prev=curr;
        curr=B[j++];
    }

    if(size%2==0)
        return (float)(prev+curr)/2;
    return curr;

}

// both arrays are sorted, using binary search
// median will have same number of elements on left and right side
// here we assume size of A <= size of B
float getMedianBinary(int A[], int B[], int m, int n)
{
    int leftMaxA, leftMaxB, rightMinA, rightMinB;
    int l {0}, h{m};
    int i, j;
    int size = m+n;
    while(l<=h)
    {
        i = l + (h-l)/2;
        // this ensures that elements in left half of both are equal or greater in left half of larger array.
        j = (m+n+1)/2 - i;

        leftMaxA = i==0 ? INT_MIN : A[i-1];
        rightMinA = i==m ? INT_MAX : A[i];
        leftMaxB = j==0 ? INT_MIN : B[j-1];
        rightMinB = j==n ? INT_MAX : B[j];

        if(leftMaxA<=rightMinB && leftMaxB<= rightMinA)
        {
            if(size%2==0)
                return (float)(max(leftMaxA, leftMaxB) + min(rightMinA, rightMinB))/2;
            else
                return (float) max(leftMaxA, leftMaxB);
        }
        else if(leftMaxA > rightMinB)
            h = i-1;
        else 
            l = i+1;
    }
    return -1;
}


int main()
{
    int m, n;
    cout<<"Enter size of first array"<<endl;
    cin>>m;
    int arr1[m];    
    takeArrayInput(arr1, m);
    cout<<"Enter size of second array"<<endl;
    cin>>n;
    int arr2[n];
    takeArrayInput(arr2, n);

    float res = getMedian(arr1, arr2, m, n);
    cout<<"Median of 2 arrays is: "<<res<<endl;

    float res2 = getMed(arr1, arr2, m, n);
    cout<<"Median of 2 arrays is: "<<res2<<endl;

    float res3 ;
    if(m<=n)
        res3 = getMedianBinary(arr1, arr2, m, n);
    else
        res3 = getMedianBinary(arr2, arr1, n, m);

    cout<<"Median of 2 arrays Binary search: "<<res3<<endl;


    return 0;
}