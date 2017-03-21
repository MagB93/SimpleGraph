#include "heterogene_relation.h"
#include <set>


template<typename E> class HomogeneRelation:
HeterogeneRelation<E, E>{

    private:
        std::set<E> basicset;

    public:
        bool isReflexive();
        bool isSymmetric();
        bool isTransitive();
        HomogeneRelation<E> getReflexiveHull();
        HomogeneRelation<E> getTransitiveHull();

};