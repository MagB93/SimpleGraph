
#include <set>
#include "heterogene_relation.h"

#ifndef HOM_REL_N
#define HOM_REL_N



template<typename E> class HomogeneRelation: public HeterogeneRelation<E, E>{

    private:
        std::set<E> basicset;

    public:
        bool isReflexive();
        bool isSymmetric();
        bool isTransitive();
        HomogeneRelation<E> getReflexiveHull();
        HomogeneRelation<E> getTransitiveHull();

};

#endif