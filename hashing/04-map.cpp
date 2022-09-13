#include <iostream>
#include <map>

using namespace std; 

int main()
{
    map<char, int> m;
    m.insert({'a',97});
    m.insert({'b',98});
    m.insert({'c',99});
    m.insert({'d',100});
    m.insert({'e',101});
    m.insert({'f',102});
    m.insert({'g',103});
    m.insert({'h',104});
    m.insert({'r',104});
    
    map<char, int> :: iterator itr;
    for(itr = m.begin();itr!=m.end();itr++)
        cout<<itr->first<<" "<<itr->second<<endl;

    // for(auto it=m.begin(); it!=m.end();it++)
    //     cout<<it->first<<": "<<it->second<<endl;

    // size
    cout<<"size of map m is "<<m.size()<<endl;

    // empty
    cout<<"map is "<<(m.empty()?"empty":"not empty")<<endl;

    // find : returns an iterator not boolean
    auto it = m.find('f');
    cout<<"find method: key f is "<<(it==m.end()?"absent":"present")<<endl;

    // erase
    m.erase(it);
    cout<<"size of map "<<m.size()<<endl;

    // max_size 
    cout<<"max size of map "<<m.max_size()<<endl;

    // count
    cout<<"count of elements with value 97 is "<<m.count(104)<<endl;


    // erase(const key)
    m.erase('e');
    cout<<"size of map "<<m.size()<<endl;

    // at 
    cout<<m.at('a')<<endl;
    // cout<<m.at('f')<<endl;
 
    // clear : removes all entries from the map withou deleting the map.
    m.clear();
    cout<<"size now is "<<m.size()<<endl;


    return 0;    
    return 0;
}