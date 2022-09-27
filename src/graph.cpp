#include "../h/graph.h"

adjacency::adjacency(node* n, double weight) {
    this->n = n;
    this->weight = weight;
}

node::node(string name) {
    this->name = name;
}

node::~node() {

}

string node::to_string() {
    string str = "name: " + this->name + ", ";

    for(adjacency a : this->adj)
        str += a.n->to_string() + ", " + std::to_string(a.weight) + ", ";

    return str;
}

void node::add_adjacency(node& n, double weight) {
    this->adj.push_back(adjacency(&n, weight));
}


graph::graph() {
    this->size = 0;
}

graph::~graph() {

}

string graph::to_string() {
    string str = "===================================\n";
    str += "size: " + std::to_string(size) + "\n";

    for(node& n : this->nodes)
        str += n.to_string() + "\n";

    str += "===================================";
    return str;
}

void graph::add_node(node n) {
    this->nodes.push_back(n);
    this->size++;
}

void graph::add_node(string name) {
    this->add_node(node(name));
}

void graph::add_edge(node& n1, node& n2, double weight) {
    n1.add_adjacency(n2, weight);
}

void graph::add_edge(string n1, string n2, double weight) {    
    for(node n : this->nodes)
        if(!n1.compare(n.name))
            for(adjacency a : n.adj) 
                if(!a.n->name.compare(n2))
                    this->add_edge(n, *a.n, weight);
}