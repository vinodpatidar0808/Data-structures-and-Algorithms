// STL sort function : included in algorithm header.
// used in collections which allows random access Array, vectors, deques ...
// internally uses Intro sort (hybrid of quick, heap and insertion sort.)


#include <iostream>
#include <algorithm>
#include <vector>


using namespace std; 



void sortArray()
{
    int arr[] {5,7,9,54,31,25,64,12,11,232,10,9,7,8,6,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    // this is not stable
    sort(arr, arr+n);
    // for stability
    // stable_sort(arr, arr+n);
    cout<<"Sorting in ascending order: "<<endl;
    for(int x: arr)
        cout<<x<<" ";
    cout<<endl;
    
    sort(arr, arr+n, greater<int>());
    cout<<"Sorting in descending order: "<<endl;
    for(int x: arr)
        cout<<x<<" ";
    cout<<endl;
}


void sortVector()
{   
    cout<<endl<<"Sorting a vector"<<endl;
    vector<int> vect{5,75,8,9,10,4,6,3,2,10,15,12,65,24,19,35};
    sort(vect.begin(),vect.end());
    cout<<"Ascending order:"<<endl;
    for(int x: vect)
        cout<<x<<" ";
    cout<<endl;

    // descending order
    sort(vect.begin(),vect.end(),greater<int>());
    cout<<"Descending order:"<<endl;
    for(int x: vect)
        cout<<x<<" ";
    cout<<endl;
}

// custom comparator
struct coordinate{
    int x, y;
};

bool myComparison(coordinate c1, coordinate c2)
{
    return c1.x <= c2.x;
    // for descending order/ reverse sorting
    // return c1.x > c2.x;
}

void customComparator()
{
    coordinate arr[] {{5,3},{2,5},{4,6},{8,9},{6,10},{7,12},{12,11},{4,3}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,myComparison);
    cout<<"Ascending order:"<<endl;
    for(coordinate c : arr)
    cout<<"("<<c.x<<" "<<c.y<<") ";
    cout<<endl<<endl;
}

int main()
{
    sortArray();  
    sortVector();
    customComparator();
    return 0;
}