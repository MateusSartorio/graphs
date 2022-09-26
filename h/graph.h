#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct node {
    private:
        string name;
        vector<node*> adj;
        // vector<int> v;
    
    public:
        node(string name);
        // ~node();

        string to_string();    
};

struct graph {
    private:
        vector<node> vertices;
        unsigned int size;

    public:
        graph();
        ~graph();

        string to_string();

        graph& add_node(string name);
        graph& add_node(node n);
};