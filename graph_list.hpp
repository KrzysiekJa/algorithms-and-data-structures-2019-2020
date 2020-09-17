#ifndef GRAPH_LIST_H_
#define GRAPH_LIST_H_

#include <string>
#include <iostream>
#include "node_graph.hpp"

using namespace std;



  
template<class T1, class T2>
class GraphList
{
		template<class Type> friend class Graph;
	
public:
	GraphList(){
		tail = new GNode<T1, T2>;
		head = tail;
		size = 0;
	}
	~GraphList(){
		delete tail;
	}
	
	void insertBegin(T1 vertex, T2 value);
	void print();
	T2	 search(T1 v_value);
	
private:
	GNode<T1, T2> * head;
	GNode<T1, T2> * tail;
	int    size;
};




template<class T1, class T2>
void GraphList<T1, T2>::insertBegin(T1 vertex, T2 value){
	
	GNode<T1, T2> * temp = new GNode<T1, T2>;
	
	temp -> vertex = vertex;
	temp -> val  = value;
	temp -> next = head;
	++size;
	head = temp;
}


template<class T1, class T2>
void GraphList<T1, T2>::print(){
	
	if(head == tail){
		cout << "Empty." << endl;
		return;
	}
	
	for(GNode<T1, T2> * elem = head; elem != tail;elem = elem -> next){
		cout << elem -> vertex << " : " << elem -> val << " ,";
	}
	cout << endl;
}


template<class T1, class T2>
T2 GraphList<T1, T2>::search(T1 v_value){
	
	GNode<T1, T2> * elem = head;
	while(elem && elem -> vertex != v_value){
		elem = elem -> next;
	}
	
	if (elem == nullptr){
		throw "No such element";
	}
	return elem -> val;
}


#endif /* GRAPH_LIST_H_ */