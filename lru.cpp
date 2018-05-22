#include<bits/stdc++.h>
#include <list>
using namespace std;
list<int,int> used;
unordered_map<int, list<int,int>::iterator > cache;

int _capacity;


void touch(unordered_map<int, list<int>::iterator>::iterator it)
{
    int value = *(it->second);
    used.erase(it->second);
    used.push_front(value);
    it->second = used.begin();
}


void clean(int capacity)
{
        _capacity=capacity;
        cache.clear();
        used.clear();
}


int get(int key) 
{
    unordered_map<int, list<int>::iterator >::iterator it = cache.find(key);
    if (it == cache.end()) return -1;
    touch(it);
    return *(it->second);
}

void Set(int key, int value) {
    unordered_map<int, list<int>::iterator >::iterator it = cache.find(key);
    if (it != cache.end()) touch(it);
    else {
        if (cache.size() == _capacity) {
            cache.erase(used.back());
            used.pop_back();
        }
        used.push_front(value);
    }
    cache[key] = used.begin();
}

int main()
{
    clean(1);
    Set(2,1);
    cout<<get(2)<<endl;
    Set(3,2);
    cout<<get(2)<<endl;
    cout<<get(3)<<endl;

    return 0;
}
