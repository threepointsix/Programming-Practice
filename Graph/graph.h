#pragma once
#include <unordered_map>
#include <unordered_set>
#include <list>


using namespace std;
class graph {
	unordered_map<int, unordered_set<int>> adj_l;

public:
	void ADDVERTEX(int n);
	void ADDEDGE(int m, int n);
	void REMOVEVERTEX(int n);
	void REMOVEEDGE(int m, int n);
	void print();
	list<int> dfs(int n);
	void strongly_connected_comp();
	list<int> ordered_adj_vertices(int n);
};