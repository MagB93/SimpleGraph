#include "directed_graph.h"
#include "binary_relation.h"
#include <set>

template <typename V> class DefaultDirectedGraph: DirectedGraph<V>{

    protected:
        std::set<V> vertices;
        BinaryRelation<V, V> relation;

    private:
        bool isSubGraphOf(DirectedGraph<V> graph);
        bool isAcrylic();
        std::set<V> get_k_predecessors(V vertex, int k);
        std::set<V> get_K_successors(V vertex, int k);

};
