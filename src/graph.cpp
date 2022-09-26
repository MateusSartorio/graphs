#include "../h/graph.h"

node::node(string name) {
    this->name = name;
}

// node::~node() {

// }

string node::to_string() {
    return "name: " + this->name;
}

graph::graph() {
    this->size = 0;
}

graph::~graph() {

}

string graph::to_string() {
    string str = "size: " + std::to_string(size) + "\n";

    for(node& n : this->vertices)
        str += n.to_string() + "\n";

    return str;
}

graph& graph::add_node(node n) {
    this->vertices.push_back(n);
    return *this;
}

graph& graph::add_node(string name) {
    this->add_node(node(name));
    return *this;
}
