#include <iostream>
#include "graph.hpp"

using namespace std;



int main(void)
{
	Graph<int> graph;
	graph.loadFromFile("graph.txt");
	
	graph.print();
	
	graph.adjacencyMatrix();
	
		
	cout << "Edges a and f are connected: " << graph.check('a', 'f') << endl;
	cout << "Edges d and g are connected: " << graph.check('d', 'g') << endl;
	cout << endl;
	
	graph.BFS('a');
}