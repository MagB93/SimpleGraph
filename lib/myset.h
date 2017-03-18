#include<set>

#ifndef MYSET_N
#define MYSET_N

#endif

template<typename T> class MySet: std::set<T>{
    public:
        bool contains(T MySet);
        bool isSubsetOf(MySet<T> set);
        MySet<T> section(MySet<T> set);
        MySet<T> union(MySet<T> set);

};