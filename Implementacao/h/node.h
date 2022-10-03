#pragma once

#include "./adjacency.h"

struct node {
    public:
        bool visited;
        bool finished;
        node* parent;
        int component;

        int discoreved_time;
        int finished_time;
        
        string name;
        vector<adjacency> adj;
    
        node(string name);
        ~node();

        string to_string();

        void add_adjacency(node& n, double weight);
};