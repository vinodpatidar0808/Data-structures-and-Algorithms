// in built binary_search , returns true/false for element to be searched. Does not return position of the element.
// binary_search is include in algorithm library


#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


using namespace std;

void stdBinarySearch()
{
    cout<<"---Binary search Vector---"<<endl;
    vector<int> v {5,10,15,20,25,30,35,40,45,50};
    bool res = binary_search(v.begin(), v.end(), 55);
    cout<<(res ? "present": "not present")<<endl;
    
    bool res2 = binary_search(v.begin(), v.end
    (), 50);
    cout<<(res2 ? "present": "not present")<<endl;

    cout<<endl;

    cout<<"--- Binary search STL array ---"<<endl;
    array <int,10> arr{5,10,15,20,25,30,35,40,45,50};
    
    bool res3 = binary_search(arr.begin(), arr.end(), 35);
    cout<<(res3 ? "present": "not present")<<endl;
    
    bool res4 = binary_search(arr.begin(), arr.end(), 33);
    cout<<(res4 ? "present": "not present")<<endl;
    cout<<endl;
    
    cout<<"--- Binary search on array ---"<<endl;
    int arr1[10] {10,20,30,40,50,60,70,80,90,100};
    
    int n = sizeof(arr1)/sizeof(arr1[0]);
    
    bool res5 = binary_search(arr1, arr1 + n, 103);
    cout<<(res5 ? "present": "not present")<<endl;
    bool res6 = binary_search(arr1 , arr1 + n, 90);
    cout<<(res6 ? "present": "not present")<<endl;
    cout<<endl;
}


// both upper_bound and lower_bound returns iterator to the bound
void bounds()
{   
    cout<<"*** Upper bound ***"<<endl;
    cout<< "--------vector-----------"<<endl;
    vector<int> v {5,10,15,20,25,30,35,40,45,50};

    vector<int>::iterator up1, up2;
    up1 = upper_bound(v.begin(),v.end(), 40);
    int index_up1 = up1 - v.begin();
    cout<<*up1<<" index "<<index_up1<<endl;

    up2 = upper_bound(v.begin(),v.end(),60);
    // when  upper bound does not exist it will return v.end()
    int index_up2 = up2 - v.begin();
    cout<<(up2 !=v.end() ? "upper bound  exist ": "upper bound does not exist")<<endl;

    cout<<endl;

    cout<<"--STL arrays--"<<endl;
    array <int,10> arr{5,10,15,20,25,30,35,40,45,50};
    array <int,10> :: iterator ar1, ar2;
    ar1 = upper_bound(arr.begin(),arr.end(),15);
    cout<<*ar1<<" index "<<ar1 - arr.begin() <<endl;
    
    ar2 = upper_bound(arr.begin(),arr.end(),50);
    if(ar2 == arr.end())
        cout<<"no upper bound exist "<<endl;
    cout<<endl;

    cout<<"---- on arrays ----"<<endl;
    int arr1[10] {10,20,30,40,50,60,70,80,90,100};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int upper1 = upper_bound(arr1, arr1 + n, 85) - arr1;
    // int index = upper1 - arr;
    cout<<"upper bound of 85 exist at index "<<upper1<<endl;
    // int upper2 = upper_bound(arr1, arr1 + n, 100);
    // if upper bound does not exist it will give index of last element + 1
    int upper2 = upper_bound(arr1, arr1 + n, 500) - arr1;
    cout<<upper2<<endl;

    cout<<endl;
    
    // in similar way lower bound works
}

int main(){
    stdBinarySearch();
    bounds();
    return 0;
}