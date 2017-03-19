#include <set>
#include "pair.h"

#ifndef BINREL_N
#define BINREL_N

template<typename E1, typename E2> class BinaryRelation{
    
    private: 
        std::set<Pair<E1, E2> > set;

    public:
        bool add(E1 first, E2 second){
            set.emplace(first, second);
        };

        bool remove(E1 first, E2 second){
            auto search = set.find(Pair<E1, E2>(first, second)); 
            if(search != set.end()) {
                return true;
            }
            else {
                return false;
            }
        };

        BinaryRelation<E2, E1> transposition(){
            
            BinaryRelation<E2, E1> bin = new BinaryRelation();
            for(auto it = set.begin(); it != set.end(); ++it){
                bin.emplace(it.getSecond(), it.getFirst());
            }

            return bin;
        };

        template<typename E3> BinaryRelation<E1, E3> 
        product(BinaryRelation<E2, E3> relation){

            BinaryRelation<E1, E3> bin = new BinaryRelation();

            for(auto it1 = set.begin(); it1 != set.end(); ++it1){

                for(auto it2 = relation.set.begin(); 
                    it2 != relation.set.end(); ++it2){
                        if(it1 <= it2){
                            bin.add(it1.getFirst(), it2.getSecond());
                        }
                    }
            }

        };

        
}
#endif