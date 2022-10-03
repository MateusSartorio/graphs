#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct node;

struct adjacency {
    public:
        node* n;
        double weight;

        adjacency(node* n, double weight);
};