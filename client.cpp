#include <iostream>
#include <vector>

#include "./h/graph.h"

using namespace std;

int main(int argc, char** argv) {
    graph g;
    g.add_node("a");
    g.add_node("b");
    g.add_node("c");

    g.add_edge("a", "b", 1);
    g.add_edge("b", "a", 2);

    cout << g.to_string() << endl;

    return 0;
}