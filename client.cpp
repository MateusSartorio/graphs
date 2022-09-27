#include <iostream>
#include <vector>

#include "./h/graph.h"

using namespace std;

int main(int argc, char** argv) {
    graph g;
    g.add_node("a");
    g.add_node("b");
    g.add_edge("a", "b", 1);

    cout << g.to_string() << endl;

    return 0;
}