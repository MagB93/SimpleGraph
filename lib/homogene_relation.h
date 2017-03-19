#include "heterogene_relation.h"
#include "MySet"

#ifndef HOM_REL_N
#define HOM_REL_N

template<typename E> class HomogeneRelation:
HeterogeneRelation<E, E>{

    private:
        MySet<E> basicset;

    public:
        bool isReflexive();
        bool isSymmetric();
        bool isTransitive();
        HomogeneRelation<E> getReflexiveHull();
        HomogeneRelation<E> getTransitiveHull();
        HomogeneRelation<E> getTransitiveHull();

}
#endif