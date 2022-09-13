#include <iostream>
#include <unordered_map>
#include <iterator>


using namespace std; 

int main()
{
    unordered_map<char, int> mapUnorderd;
    mapUnorderd.insert({'a',97});
    mapUnorderd.insert({'b',98});
    mapUnorderd.insert({'c',99});
    mapUnorderd.insert({'d',100});
    mapUnorderd.insert({'e',101});
    mapUnorderd.insert({'f',102});
    mapUnorderd.insert({'g',103});
    mapUnorderd.insert({'h',104});
    
    unordered_map<char, int> :: iterator itr;
    for(itr = mapUnorderd.begin();itr!=mapUnorderd.end();itr++)
        cout<<itr->first<<" "<<itr->second<<endl;

    // for(auto it=mapUnorderd.begin(); it!=mapUnorderd.end();it++)
    //     cout<<it->first<<": "<<it->second<<endl;

    // size
    cout<<"size of mapUnordered is "<<mapUnorderd.size()<<endl;

    // empty
    cout<<"mapUnordered map is "<<(mapUnorderd.empty()?"empty":"not empty")<<endl;

    // find : returns an iterator not boolean
    auto it = mapUnorderd.find('f');
    cout<<"find method: key f is "<<(it==mapUnorderd.end()?"absent":"present")<<endl;

    // erase
    mapUnorderd.erase(it);
    cout<<"size of map "<<mapUnorderd.size()<<endl;

    // erase(const key)
    mapUnorderd.erase('e');
    cout<<"size of map "<<mapUnorderd.size()<<endl;

    // at 
    cout<<mapUnorderd.at('a')<<endl;
    // cout<<mapUnorderd.at('f')<<endl;
 
    // bucket_count : returns total number of buckets in unordered_map
    cout<<mapUnorderd.bucket_count()<<endl;

    //bucket_size: returns the number of elements in each bucket of unordere_map
    // bucket numbers from 0 to bucket_count - 1
    cout<<mapUnorderd.bucket_size(0)<<endl;
    
    
    // bucket(key): Returns the bucket number where the element with the key k is located in the map.
    cout<<mapUnorderd.bucket('b')<<endl;

    // clear : removes all entries from the map withou deleting the map.
    mapUnorderd.clear();
    cout<<"size now is "<<mapUnorderd.size()<<endl;


    return 0;
}