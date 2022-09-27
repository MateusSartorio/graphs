#include <iostream>
#include <vector>

#include "./h/graph.h"

using namespace std;

int main(int argc, char** argv) {
    graph g(false, false);
    
    string nodes[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    int n = 9;

    g.add_node(nodes, n);

    g.add_edge("a", "b");
    g.add_edge("a", "c");
    g.add_edge("a", "d");

    g.add_edge("b", "d");
    g.add_edge("b", "e");

    g.add_edge("c", "d");
    
    g.add_edge("d", "e");
    g.add_edge("d", "f");

    g.add_edge("e", "f");
    
    g.add_edge("g", "h");
    g.add_edge("g", "i");

    g.add_edge("h", "i");

    g.dfs_componentes_nao_conectados();

    cout << g << endl;

    return 0;
}