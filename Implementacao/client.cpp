#include <iostream>
#include <vector>

#include "./h/graph.h"

using namespace std;

int main(int argc, char** argv) {
    graph g(true, false);
    
    string nodes[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    int n = 9;

    g.add_node(nodes, n);

    g.add_edge("a", "b");
    g.add_edge("a", "d");

    g.add_edge("b", "e");

    g.add_edge("c", "a");
    g.add_edge("c", "d");
    
    g.add_edge("d", "b");
    g.add_edge("d", "f");

    g.add_edge("e", "d");
    
    g.add_edge("g", "f");
    g.add_edge("g", "h");

    g.add_edge("h", "i");

    g.add_edge("i", "g");

    g.dfs_componentes_nao_conectados();

    cout << g << endl;

    g.directed_dfs();

    return 0;
}