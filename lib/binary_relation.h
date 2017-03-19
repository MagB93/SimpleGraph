#include myset.h
#include pair.h

#ifndef BINREL_N
#define BINREL_N

template<typename E1, typename E2> class BinaryRelation: 
MySet<Pair<E1, E2>>{

    public:
        bool add(E1 first, E2 second);
        bool remove(E1 first, E2 second);
        BinaryRelation<E2, E1> transposition();
        template<typename E3> BinaryRelation<E1, E3> 
            product(BinaryRelation<E2, E3>);
        
}
#endif