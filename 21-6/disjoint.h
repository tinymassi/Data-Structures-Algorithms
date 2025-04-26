// **************************************************************** //
// This header file contains the declaration of the DisjointSet     //
// class and all its public and private counterparts. The code for  //
// each function can be found in disjoint.cpp. The DisjointSet      //
// class provides functions that allow the user to create n sets,   //
// union two sets, and check if two sets share the same parent node //
//                                                                  //
// author: massimoginella12@gmail.com                               //
// **************************************************************** //

#ifndef DISJOINT_H
#define DISJOINT_H

class DisjointSet {
    public:
        DisjointSet(int n);
        void Union(int x, int y);
        int find(int x);
        int num_sets();    
        ~DisjointSet();

    private:
        void make_set(int x);
        void link(int x, int y);
        bool same_component(int x, int y);
        int* parent;
        int* rank;
        const int num_nodes = 0;
        int amt_sets = 0;
};


#endif