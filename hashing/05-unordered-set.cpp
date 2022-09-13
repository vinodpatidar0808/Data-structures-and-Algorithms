#include <iostream>
#include <unordered_set>
#include <set>
#include <iterator>

using namespace std; 

void printSet(unordered_set<int> &s)
{
    unordered_set<int>:: iterator itr;
    for(itr=s.begin(); itr!=s.end();itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}


int main()
{
    unordered_set<int> setUnordered;
    unordered_set<int> s;
    set<int> s1;
    cout<<boolalpha;
    //insert
    for(int i=1;i<10;i++)
    {
        setUnordered.insert(i);
        setUnordered.insert(i*2);
        s1.insert(i);
        s1.emplace(i*3);
    }

    //begin and end
    printSet(setUnordered);

    for(auto it=s1.begin();it!=s1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //count
    cout<<"count of 2 in the set is : "<<setUnordered.count(2)<<endl;

    //find
    auto it = setUnordered.find(10);
    cout<<"10 is present at "<<(*it)<<endl; 

    // cbegin()
    // cend()

    // erase
    setUnordered.erase(setUnordered.find(14));
    printSet(setUnordered);

    // size
    cout<<"size of set is "<<setUnordered.size()<<endl;

    // swap
    s.swap(setUnordered);
    printSet(s);
    printSet(setUnordered);
    cout<<"size of setUnordered and s after swapping "<<setUnordered.size()<<" "<<s.size()<<endl;

    // emplace()
    setUnordered.emplace(10);
    printSet(setUnordered);

    // max_size()
    cout<<"max size of setUnordered and s is "<<setUnordered.max_size()<<" "<<s.max_size()<<endl;

    // empty
    cout<<"is setUnordered empty :"<<setUnordered.empty()<<endl;
    cout<<"is s empty :"<<s.empty()<<endl;

    // =
    setUnordered = s;
    // ==
    cout<<(setUnordered == s)<<endl;

    // !=
    cout<<(setUnordered != s)<<endl;

    // clear
    s.clear();
    cout<<"is s empty :"<<s.empty()<<endl;

    return 0;
}