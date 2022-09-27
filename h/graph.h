#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct node;

struct adjacency {
    public:
        node* n;
        double weight;

        adjacency(node* n, double weight);
};

struct node {
    public:
        string name;
        vector<adjacency> adj;
    
        node(string name);
        ~node();

        string to_string();

        void add_adjacency(node& n, double weight);
};

struct graph {
    private:
        vector<node> nodes;
        unsigned int size;

    public:
        graph();
        ~graph();

        string to_string();

        void add_node(string name);
        void add_node(node n);

        void add_edge(node& n1, node& n2, double weight);
        void add_edge(string n1, string n2, double weight);

        void dfs_componentes_nao_conectados();
        void dfs();
};

ostream& operator<<(ostream& os, graph& g);