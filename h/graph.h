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
        bool visited;
        bool finished;
        node* parent;
        int component;

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

        bool is_directed;
        bool is_weighted;

        void add_node(node n);
        void add_edge(node& n1, node& n2, double weight);
    
        void dfs(node& n, int c);
        void directed_dfs(node& n, int& time);

    public:
        graph(bool is_directed = false, bool is_weighted = false);
        ~graph();

        string to_string();

        void add_node(string name);
        void add_node(string nodes[], int n);
        void add_edge(string n1, string n2, double weight = 1.0);

        void dfs_componentes_nao_conectados();
        void directed_dfs();
};

ostream& operator<<(ostream& os, graph& g);