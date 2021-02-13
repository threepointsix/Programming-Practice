#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <math.h>
#include "stack.h"
#include "used.h"
#include "graph.h"

using namespace std;

void main() {

	graph g;
	g.ADDVERTEX(1);
	g.ADDVERTEX(2);
	g.ADDVERTEX(3);
	g.ADDVERTEX(4);
	g.ADDEDGE(1, 3);
	g.ADDEDGE(3, 2);
	g.ADDEDGE(2, 2);
	g.ADDEDGE(1, 2);
	g.ADDEDGE(1, 4);
	g.ADDEDGE(3, 4);
	g.print();
	g.dfs(1);
	g.dfs(2);
	g.dfs(3);
	g.dfs(4);
	g.strongly_connected_comp();


	//graph second_example;
	//second_example.ADDVERTEX(1);
	//second_example.ADDVERTEX(2);
	//second_example.ADDVERTEX(3);
	//second_example.ADDVERTEX(4);
	//second_example.ADDVERTEX(5);
	//second_example.ADDEDGE(1, 3);
	//second_example.ADDEDGE(3, 2);
	//second_example.ADDEDGE(3, 1);
	//second_example.ADDEDGE(2, 1);
	//second_example.ADDEDGE(4, 3);
	//second_example.ADDEDGE(5, 3);
	//second_example.ADDEDGE(4, 5);
	//second_example.ADDEDGE(5, 4);
	//second_example.print();
	//second_example.strongly_connected_comp();

}



