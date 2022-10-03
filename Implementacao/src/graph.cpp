#include "../h/graph.h"


graph::graph(bool is_directed, bool is_weighted) 
    : size(0), is_directed(is_directed), is_weighted(is_weighted)
{}

graph::~graph() {}

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

void graph::directed_dfs_aux(node& n, int& time) {
    n.visited = true;
    time++;
    n.discoreved_time = time;

    for(adjacency& a : n.adj) {
        node& m = *a.n;

        if(!m.visited) {
            m.parent = &n;
            cout << "Aresta(" << n.name << ", " << m.name << ") eh uma aresta da arvore" << endl;
            directed_dfs_aux(m, time);
        }
        else if(!n.finished)
            cout << "Aresta(" << n.name << ", " << m.name << ") eh uma aresta de retorno" << endl;
        else if(n.discoreved_time < m.discoreved_time)
            cout << "Aresta(" << n.name << ", " << m.name << ") eh uma aresta para diante" << endl;
        else
            cout << "Aresta(" << n.name << ", " << m.name << ") eh uma aresta de cruzamento" << endl;
    }

    n.finished = true;
    time++;
    n.finished_time = time;
}

void graph::directed_dfs() {
    if(!this->is_directed) {
        cout << "The graph is not directed! - directed_dfs()" << endl;
        exit(1);
    }

    for(node& n : this->nodes) {
        n.visited = false;
        n.finished = false;
        n.parent = nullptr;
    }

    int time = 0;

    for(node& n : this->nodes)
        if(!n.visited)
            directed_dfs_aux(n, time);
}

ostream& operator<<(ostream& os, graph& g) {
    return cout << g.to_string();
}