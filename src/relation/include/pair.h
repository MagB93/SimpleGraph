
#include<iostream>
#ifndef PAIR_N
#define PAIR_N
template <typename E1, typename E2> class Pair{
    private:
        E1 first; E2 second;

    public:
        Pair(E1 e1, E2 e2){
            first = e1; 
            second = e2;
        };

        Pair(const Pair<E1, E2> &pair){
           Pair<E1, E2> my_pair = new Pair();
           *my_pair = *pair.ptr;  //Copy the *value* of the passed adress
        };

        // =========== Functions 

        Pair<E2, E1> transpose(){
            return new Pair<E2, E1>(second, first);
        };

        char* toString(){
            return ("(" + first + ", " + second + ")");
        };

        // =========== Getter/ Setter =======
        E1 getFirst(){
            return *first;
        };

        E2 getSecond(){
            return *second;
        };

        bool setFirst(E1 &e1){
            *first = *e1;
        };

        bool setSecond(E2 &e2){
            *second = *e2;
        };

        //=========== Operators ==========
        
        /** Operator to check wether start point of 'this' is the end point of the passed pair.
        * @param pair pointer address to a Pair<E1, E2>.
        */
        bool operator>=(const Pair<E1, E2> &pair){
            return getFirst() == pair.getSecond();
        };

        /** Operator to check wether the end point of 'this' is the start point in the passed pair.
        * @param pair pointer address to a Pair<E1, E2>.
        */
        bool operator<=(const Pair<E1, E2> &pair){
            return getSecond() == pair.getFirst();
        }

};

#endif