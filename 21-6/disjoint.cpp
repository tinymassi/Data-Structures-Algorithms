// ************************************************************************** // 
// This program is the function implementation of the DisjointSet class       //
// located in disjoint.h. This code is responsible for generating n sets and  //
// allows for unioning sets and returning whether or not nodes are a part of  //
// the same sets.                                                             //
//                                                                            //
// author: massimoginella12@gmail.com                                         //
// ************************************************************************** //

#include <iostream>
#include "disjoint.h"


// TODO: should we have boundary checks in the constructor??
DisjointSet::DisjointSet(int n) : num_nodes(n){
    if (n >= 0) {
        parent = new int [n];
        rank = new int [n];

        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    } else {
        std::cerr << "Disjoint set size invalid. Make sure size is > 0." << std::endl;
    }
}


// BOUNDS CHECK FIXED
void DisjointSet::Union(int x, int y){
    if (x < 0 || x >= num_nodes || y < 0 || y >= num_nodes) {
        std::cerr << "Node " << x << " cannot exceed or fall short of set size " << (num_nodes - 1) << std::endl;
        return;
    }

    link(find(x), find(y));
}


int DisjointSet::find(int x) {
    if (x < 0 || x >= num_nodes) {
        std::cerr << "Node " << x << " cannot exceed or fall short of set size " << (num_nodes - 1) << std::endl;
        return -1;
    }

    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }

    return parent[x];
}


void DisjointSet::make_set(int x) {
    amt_sets++;
    parent[x] = x;
    rank[x] = 0;
}


void DisjointSet::link(int x, int y) {
    if (x == -1 || y == -1 || same_component(x, y)) {
        return;
    }

    amt_sets--;

    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}


bool DisjointSet::same_component(int x, int y) {
    return (find(x) == find(y));
}


int DisjointSet::num_sets() {
    return amt_sets;
}


// FIXED INVALID DELETE SYNTAX!
DisjointSet::~DisjointSet() {
    delete[] rank;
    delete[] parent;
}