#include "graph.h"

#ifndef DIR_GRAPH_N
#define DIR_GRAPH_N 

template <typename V> class DirectedGraph: Graph{
    private:
        virtual int in_degree_of(V vertex);
        virtual int out_degree_of(V vertex);
        virtual MySet<Pair<V, V>> incoming_edges_of(V vertex);
        virtual MySet<Pair<V, V>> outgoing_edges_of(V vertex);
        virtual MySet<V> get_predecessors(V vertex);
        virtual MySet<V> get_successors(V vertex);
        
}
#endif