#include "pair.h"
#include <set>

#ifndef GRAPH_N
#define GRAPH_N

// Declarations for the graph classes
template <typename V> class Graph{
    private:
        int number_of_vertices;
        int number_of_edges;

    public: 

        virtual bool add_edge(V source, V target);
        virtual bool add_edge(Pair<V, V> pair);
        virtual bool add_vertex(V vertex);
        virtual bool contains_edge(Pair<V, V> edge);
        virtual bool contains_edge(V source, V target);
        virtual bool contains_vertex(V vertex);
        virtual std::set<Pair<V, V> > get_edge();
        virtual std::set<Pair<V, V> > get_vertices();
        virtual int get_number_of_vertices();
        virtual int get_number_of_edges();
        virtual bool set_number_of_vertices();
        virtual bool set_number_of_edges();
        virtual bool remove_vertex(V vertex);
        virtual bool remove_edge(std::set<Pair<V, V> >);
        virtual bool remove_edge(V source, V target);
        
};

#endif