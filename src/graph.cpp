#include "../h/graph.h"

adjacency::adjacency(node* n, double weight) {
    this->n = n;
    this->weight = weight;
}

node::node(string name) {
    this->name = name;
}

node::~node() {
    //Nothing to do in here
}

string node::to_string() {
    string str = this->name;

    if(!this->adj.empty()) {
        str += " | ";
        for(adjacency a : this->adj)
            str += "(" + a.n->name + ", " + std::to_string(a.weight) + "), ";
    }
    else
        str += " | no adjacencies";

    return str;
}

void node::add_adjacency(node& n, double weight) {
    if(!this->name.compare(n.name))
        return;

    this->adj.push_back(adjacency(&n, weight));
}


graph::graph() {
    this->size = 0;
}

graph::~graph() {

}

string graph::to_string() {
    string str = "==================================\n";
    str += "size: " + std::to_string(size) + "\n";
    str += "----------------------------------\n"; 

    for(node& n : this->nodes)
        str += n.to_string() + "\n";

    str += "===================================";
    return str;
}

void graph::add_node(node n) {
    for(node n_temp : this->nodes)
        if(!n_temp.name.compare(n.name))
            return;

    this->nodes.push_back(n);
    this->size++;
}

void graph::add_node(string name) {
    this->add_node(node(name));
}

void graph::add_edge(node& n1, node& n2, double weight) {
    for(adjacency& a : n1.adj)
        if(!a.n->name.compare(n2.name))
            return;
    
    n1.add_adjacency(n2, weight);
}

void graph::add_edge(string n1, string n2, double weight) {    
    node* node1 = nullptr;
    node* node2 = nullptr;
    int count = 0;

    for(node& n : this->nodes) {
        if(!n1.compare(n.name)) {
            node1 = &n;
            count++;
        }
        else if(!n2.compare(n.name)) {
            node2 = &n;
            count++;
        }
        
        if(count == 2)
            break;
    }

    if(count < 2)
        return;    
    
    this->add_edge(*node1, *node2, weight);
}