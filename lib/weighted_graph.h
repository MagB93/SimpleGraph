#include "graph.h"

#ifndef WEIGHT_GRAPH_N
#define WEIGHT_GRAPH_N

template <typename V, typename W> class WeightedGraph: Graph{

    public:
        virtual bool add_edge(V source, V target, W weight);
        virtual bool add_edge(MySet<Pair<V, V>, W weight);
        virtual bool set_edge_weight(MySet<Pair<V, V>, W weight);
        virtual W get_edge_weight(MySet<Pair<V, V>);

}
#endif