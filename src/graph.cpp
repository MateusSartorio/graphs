#include "../h/graph.h"

adjacency::adjacency(node* n, double weight) {
    this->n = n;
    this->weight = weight;
}

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


graph::graph(bool is_directed, bool is_weighted) {
    this->size = 0;
    this->is_directed = is_directed;
    this->is_weighted = is_weighted;
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

void graph::add_node(string nodes[], int n) {
    for(int i = 0; i < n; i++)
        this->add_node(nodes[i]);
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

    if(!this->is_weighted)
        weight = 1.0;
    
    this->add_edge(*node1, *node2, weight);
    if(!this->is_directed)
        this->add_edge(*node2, *node1, weight);
}

void graph::dfs(node& n, int c) {
    n.visited = true;
    n.component = c;

    for(adjacency& a : n.adj) {
        node& m = *a.n;

        if(!m.visited) {
            m.parent = &n;
            cout << "parent of " << m.name << " is " << n.name << endl;
            dfs(m, c);
        }
        // else if(m.visited && !m.finished)
        //     cout << "(" << n.name << ", " << m.name << ") is a returning edge" << endl;
    }
    n.finished = true;
}

void graph::dfs_componentes_nao_conectados() {
    int c = 0;

    for(node& n : this->nodes) {
        n.visited = false;
        n.finished = false;
        n.parent = nullptr;
    }

    for(node& n : this->nodes)
        if(!n.visited) {
            c++;
            dfs(n, c);
        }
}

void graph::directed_dfs(node& n, int& time) {
    n.visited = true;
    time++;
    
}

void graph::directed_dfs() {
    for(node& n : this->nodes) {
        n.visited = false;
        n.finished = false;
        n.parent = nullptr;
    }

    int time = 0;

    for(node& n : this->nodes)
        if(!n.visited)
            directed_dfs(n);
}

ostream& operator<<(ostream& os, graph& g) {
    return cout << g.to_string();
}