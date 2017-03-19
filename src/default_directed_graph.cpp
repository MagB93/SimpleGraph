#include "directed_graph.h"
#include "homogene_relation.h"

template <typename V> class DefaultDirectedGraph: DirectedGraph{

    protected:
        MySet<V> vertices;
        HomogeneRelation<V> relation;

    private:
        bool isSubGraphOf(DirectedGraph<V> graph);
        bool isAcrylic();
        MySet<V> get_k_predecessors(V vertex, int k);
        MySet<V> get_K_successors(V vertex, int k);

}
