#include "../h/node.h"

node::node(string name) {
    this->name = name;

    this->visited = false;
    this->finished = false;
    this->parent = nullptr;
    this->component = 0;
}

node::~node() {
    //Nothing to do in here
}

string node::to_string() {
    string str = this->name;

    if(!this->adj.empty()) {
        str += " | ";
        for(adjacency a : this->adj) {
            str += "(" + a.n->name + ", " + std::to_string(a.weight) + "), ";
        }
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