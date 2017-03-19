#include<list>

#ifndef MYSET_N
#define MYSET_N


template<typename T> class MySet: std::list<T>{
    private:
        T[] array;
        int size;

    public:
        bool contains(T MySet);
        bool isSubsetOf(MySet<T> set);
        MySet<T> section(MySet<T> set);
        MySet<T> union(MySet<T> set);

};
#endif