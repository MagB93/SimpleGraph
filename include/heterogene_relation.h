#include "binary_relation.h"

#ifndef HET_REL_N
#define HET_REL_N

template<typename E1, typename E2> class HeterogeneRelation:
    BinaryRelation<E1, E2>{
        private:
           MySet<E1> preImage;
           MySet<E2> image;

        public:
            bool isLeftTotal;
            bool isRightTotal;
            bool isRightUnique;
            bool isLeftUnique;

    }

#endif