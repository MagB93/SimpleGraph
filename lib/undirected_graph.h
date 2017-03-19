#include "graph.h"

#ifndef UNDIR_GRAPH_N
#define UNDIR_GRAPH_N

template <typename V> class UndirectedGraph: Graph{

    public:
        virtual int degree_Of(V vertex);
        virtual MySet<Pair<V, V>> get_neighbours(V vertex);
        virtual MySet<Pair<V, V>> neighbour_edges_of(V vertex);

}

#endif