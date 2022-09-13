#include <iostream>
#include <list>

using namespace std; 

struct Hash
{
    int size ;
    list<int> *hashTable;
    Hash(int n)
    {
        size = n;
        hashTable = new list<int>[size];
    }

    void insert(int key)
    {
        // calculate hash
        int i = key%size;
        hashTable[i].push_back(key);
    }

    void remove(int key)
    {
        //get index
        int i = key%size;
        hashTable[i].remove(key);
    }

    bool search(int key)
    {
        int i = key%size;
        for(auto x: hashTable[i])
        {
            if(x==key)
                return true;
        }
        return false;
    }
    void printHashTable()
    {
        for(int i=0;i<size;i++)
        {
            cout<<i<<" --> ";
            for(auto x: hashTable[i])
                cout<<x<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};



int main()
{
    int n ;
    cout<<"enter size of hash table"<<endl;
    cin>>n;
    Hash h(n);
    h.insert(10);
    h.insert(9);
    h.insert(5);
    h.insert(4);
    h.insert(3);
    h.insert(10);
    h.printHashTable();
    // removing a non existing value
    h.remove(11);
    h.remove(10);
    h.printHashTable();
    cout<<h.search(5)<<endl;


    return 0;
}