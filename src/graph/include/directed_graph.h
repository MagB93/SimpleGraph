#include "graph.h"
#include <set>

#ifndef DIR_GRAPH_N
#define DIR_GRAPH_N 

template <typename V> class DirectedGraph: Graph<V>{
    private:
        virtual int in_degree_of(V vertex);
        virtual int out_degree_of(V vertex);
        virtual std::set<Pair<V, V>> incoming_edges_of(V vertex);
        virtual std::set<Pair<V, V>> outgoing_edges_of(V vertex);
        virtual std::set<V> get_predecessors(V vertex);
        virtual std::set<V> get_successors(V vertex);
        
};
#endif