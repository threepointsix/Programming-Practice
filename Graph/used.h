#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Used {
    unordered_map<int, bool> visited; // A map of visited verties, where <int> is a label of vertex and key value <bool> is a true/false depending whether vertex was visited before or not

public:

    Used() : visited(NULL) {};

    void add(int n, bool b) { // Adding vertice with label (int n) and initial boolean value (bool false)
        visited.insert(make_pair(n, b));
    }

    void visited_true(int n) { // Method to change a state of vertex from false to true, which means the vertex was visited
        this->visited.find(n)->second = true;
    }

    bool operator()(int n) const { // Overloading of operator(), so that Used(2) will return whether vertex with a label 2 was visited before or not
        return visited.find(n)->second == true;
    }
};