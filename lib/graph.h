#ifndef GRAPH_N
#define GRAPH_N

// Declarations for the graph classes
template <typename V> 
class Graph{
    public: 
        bool add_edge(V source, V target);
        bool add_edge(Pair<E1, E2> pair);
        
}

#endif