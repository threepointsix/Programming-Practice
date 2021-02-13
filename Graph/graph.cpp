#include "graph.h"
#include "stack.h"
#include "used.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


using namespace std;

void graph::ADDVERTEX(int n)
{
	for (auto it : this->adj_l) {
		if (it.first == n) {
			cout << "Vertex " << n << " is already in a graph" << endl;
			return;
		}
	}
	adj_l.insert(make_pair(n, NULL));
	print();
}

void graph::ADDEDGE(int m, int n)
{
	if (m == n) {
		adj_l.find(m)->second.insert(n);
		print();
		return;
	}
	auto search_m = adj_l.find(m);
	auto search_n = adj_l.find(n);


	if (search_m == adj_l.end()) {
		cout << "Vertex " << m << " is not in a graph" << endl;
		return;
	}

	if (search_n == adj_l.end()) {
		cout << "Vertex " << n << " is not in a graph" << endl;
		return;
	}

	auto search_n_in_m = search_m->second.find(n);
	if (search_n_in_m != search_m->second.end()) {
		cout << "Vertex " << n << " is already adjacent to " << m << endl;
		return;
	}
	search_m->second.insert(n);
	print();
}

void graph::REMOVEVERTEX(int n)
{
	auto search_n = adj_l.find(n);
	if (search_n == adj_l.end()) {
		cout << "Vertex " << n << " is not in a graph " << endl;
		return;
	}

	for (auto it = adj_l.begin(); it != adj_l.end(); it++) {
		if (it->first == n) {
			adj_l.erase(it);
			break;
		}
	}

	for (auto it : adj_l) {
		for (auto ot : it.second) {
			if (ot == n) {
				adj_l.find(ot)->second.erase(ot);
			}
		}
	}

	print();
}

void graph::REMOVEEDGE(int m, int n)
{
	auto search_m = adj_l.find(m);
	auto search_n = adj_l.find(n);

	if (search_m == adj_l.end()) {
		cout << "Vertex " << m << " is not in a graph" << endl;
		return;
	}

	if (search_n == adj_l.end()) {
		cout << "Vertex " << n << " is not in a graph" << endl;
		return;
	}

	auto search_n_in_m = search_m->second.find(n);
	if (search_n_in_m == search_m->second.end()) {
		cout << "There is no edge " << m << " -> " << n << endl;
		return;
	}
	else {
		search_m->second.erase(n);
	}
	print();
}

void graph::print()
{
	cout << "Graph: " << endl;
	for (auto it : adj_l) {
		cout << it.first;
		for (auto ot : it.second) {
			cout << " -> " << ot;
		}
		cout << ";" << endl;
	}
	cout << endl;
}

list<int> graph::dfs(int n)
{
	stack _stack; // My stack
	list<int> path; // Path, which will be outputed

	Used used_list;
	for (auto it : adj_l) {
		used_list.add(it.first, false); // Creating a map<int, bool>, where <int> is a vertice label and <bool> is information if this vertice was visited before. For that purpore I implemented my own class Used
	}

	_stack.push(n);

	while (!_stack.isEmpty()) { // DFS algorithm
		int vertex = _stack.pop();
		if (!used_list(vertex)) {
			used_list.visited_true(vertex);
			path.push_back(vertex);
			for (auto ot : this->ordered_adj_vertices(vertex)) { // Adding all vertices, to which current vertex point at, to the stack. I used method ordered_adj_vertices(), so that among all the vertices, it will prioritize the ones with a smaller label
				_stack.push(ot);
			}
		}
	}

	// Output of DFS

	//cout << "DFS: "; 
	//for (auto it : path) {
	//	cout << it << " ";
	//}
	//cout << endl;
	return path;
}

list<int> graph::ordered_adj_vertices(int n) { // Method to return a list of vertices, to which current vertex point at
	auto current_vertex = adj_l.find(n);
	list<int> adj_vertices;
	for (auto it : current_vertex->second) {
		adj_vertices.push_back(it);
	}
	adj_vertices.sort(); // Sorting a list of adjacent vertices, so now the list looks like [1, 2, 3, 4]
	adj_vertices.reverse(); // But when vertices will be added to the stack, stack will look like [4, 3, 2, 1], so I have to reverse the list, and now 4 will be added first, then 3, 2, and 1. So the list looks like [4, 3, 2, 1] and the stack [1, 2, 3, 4]
	return adj_vertices;
}

void graph::strongly_connected_comp() { // The main idea is: 1) I find DFS of every vertex in the graph; 2) If a DFS of two or more vertices is equal, that means they are strongly connected

	unordered_map<int, list<int>> dfs_list; // int is vertex label, list<int> is this vertex DFS path

	for (auto it : adj_l) { // Assigning labels and DFS paths
		list<int> dfs_of_vertex = dfs(it.first); // Finding DFS of vertex
		dfs_of_vertex.sort(); // Sorting a list of DFS (because list1 == list2 will return true, only if elements in the lists are equal and in the same position
		dfs_list.insert(make_pair(it.first, dfs_of_vertex)); // Inserting int label and list<int> dfs_of_vertex to my dfs_list
	}

	vector<int> anti_repeating; // Just a vector to prevent repeating outputs of strongly connected components
	for (auto it : dfs_list) {
		vector<int> strongly_connected_comp;
		for (auto ot : dfs_list) {
			if (it.second == ot.second) { // If both DFS paths are equal, then the vertices are strongly connected
				strongly_connected_comp.push_back(ot.first);
			}
		}

		if (strongly_connected_comp != anti_repeating) { // Basicly it is the output of strongly connected components, but with condition, that if this list of strongly connected components were outputted before, it won't output it again
			cout << "Strongly connected components: ";
			for (auto op : strongly_connected_comp) {
				cout << op << " ";
			}
			cout << endl;
		}
		anti_repeating = strongly_connected_comp;
	}
}