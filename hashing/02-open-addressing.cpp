// Linear probing : 

#include <iostream>
#include <limits>

using namespace std; 

// here we used -1 for empty slot and INT_MIN for deleted slot, but what if -1 and INT_MIN are also values. In libraries they don't store values directly instead they store pointers. For deleted value they use a dummy node to which all deleted node points.

struct Hash
{
    int *hashTable;
    int cap, size;

    Hash(int c)
    {
        cap = c;
        size=0;
        hashTable = new int[cap];
        for(int i=0;i<cap;i++)
            hashTable[i] = -1;
    }

    int hashFxn(int key)
    {
        return key%cap;
    }

    bool search(int key)
    {
        int h = hashFxn(key);
        int i = h;
        while(hashTable[i]!=-1)
        {
            if(hashTable[i] == key)
                return true;

            // circular traversal
            i = (i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }

    void erase(int k)
    {
        int h = hashFxn(k);
        int i = h;
        while(hashTable[i] != -1)
        {
            if(hashTable[i] == k)
            {
                hashTable[i] = INT_MIN;
                size--;
                return ;
            }
            i = (i+1)%cap;

            if(i==h)
                break ;
        }
    }

    void insert(int key)
    {
        if(size==cap)
            return;
        int i = hashFxn(key);
        while(hashTable[i]!=-1 && hashTable[i]!=-2 && hashTable[i]!=key)
            i = (i+1)%cap;
        // key already present
        if(hashTable[i] == key)
            return ;
        else
        {
            hashTable[i] = key;
            size++;
        }
    }

    void printHashTable()
    {
        for(int i=0;i<cap;i++)
        {
            cout<<i<<" --> ";
            if(hashTable[i]== -1)
                cout<<"Empty"<<endl;
            else if(hashTable[i]==INT_MIN)
                cout<<"Deleted (empty)"<<endl;
            else
                cout<<hashTable[i]<<endl;
        }
        cout<<endl;
    }
};


int main()
{
    int n ;
    cout<<"Enter maximum capacity of hash table"<<endl;
    cin>>n;
    Hash table(n);
    table.insert(10);
    table.insert(5);
    table.insert(11);
    table.insert(12);
    table.insert(13);
    table.printHashTable();
    table.erase(14);
    table.erase(10);
    table.printHashTable();
    cout<<table.search(13)<<endl;
    return 0;
}