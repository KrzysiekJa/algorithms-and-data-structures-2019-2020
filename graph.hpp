#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "graph_list.hpp"
#include "node_graph.hpp"
#include <vector>
#include <queue>

using namespace std;




template<class T>
class Graph
{
public:
	Graph(){
		tail = new GNode<char, GraphList<char, T> * >;
		head = tail;
		size = 0;
	}
	~Graph(){
		delete tail;
	}
	
	void insertBegin(char n_vertex, GraphList<char, T> * list);
	void loadFromFile(string fileName);
	void print();
	void adjacencyMatrix();
	void incidenceMatrix();
	bool check(char one, char two);
	void BFS(char vertex);
	void DFS(char vertex);
	
private:
	GNode<char, GraphList<char, T> * > * head;
	GNode<char, GraphList<char, T> * > * tail;
	int    size;
};




template<class T>
void Graph<T>::insertBegin(char n_vertex, GraphList<char, T> * list)
{
	GNode<char, GraphList<char, T> * > * temp = new GNode<char, GraphList<char, T> * >;
	
	temp -> vertex = n_vertex;
	temp -> val  = list;
	temp -> next = head;
	++size;
	head = temp;
}


template<class T>
void Graph<T>::loadFromFile(string fileName)
{
	ifstream file;
	string   str;
	char	 letter, sign;
	char	 tab[1];
	T		 found;
	
	file.open(fileName, ios::in);
	if(file.good() == false){
		return;
	}
	
	while(getline(file,str)){
		
		GraphList<char, T> * temp = new GraphList<char, T>;
		stringstream ss(str);
		ss >> letter;
        
	    while(!ss.eof()){
	        ss >> str;
			
			if(str[0] >= 'a' && str[0] <= 'z'){
				strcpy(tab, str.c_str());
				sign = tab[0];
			}
			
	        if(stringstream(str) >> found){
	        	temp -> insertBegin(sign, found);
	        }
				
	        str = "";
	    } 
		
		insertBegin(letter, temp);
	}
	
	file.close();
}


template<class T>
void Graph<T>::print()
{
	
	if(head == tail){
		cout << "Empty." << endl;
	}
	
	for(GNode<char, GraphList<char, T> * > * elem = head; elem != tail;elem = elem -> next){
		cout << "{" << elem -> vertex << "}: ";
		elem -> val -> print();
	}
	cout << endl;
}


template<class T>
void Graph<T>::adjacencyMatrix()
{
	vector<char> vec;
	
	for(GNode<char, GraphList<char, T> * > * elem = head; elem != tail;elem = elem -> next){
		vec.push_back(elem -> vertex);
	}
	
	for(GNode<char, GraphList<char, T> * > * elem = head; elem != tail;elem = elem -> next){
		
		for(char c: vec){
			try{
				elem -> val -> search(c);
				cout << "1 ";
			} catch(...){
				cout << "0 ";
			}
		}
		cout << endl;
	}
	cout << endl;
	
	vec.clear();
}



struct Edge{
	char letf, right;
};


template<class T>
bool Graph<T>::check(char one, char two)
{
	for(GNode<char, GraphList<char, T> * > * elem = head; elem != tail;elem = elem -> next){
		if(elem -> vertex == one){
			try{
				elem -> val -> search(two);
				return true;
			} catch(...){
				return false;
			}
		}
	}
}


template<class T>
void Graph<T>::BFS(char vertex)
{
	queue<char> que;
	que.push(vertex);
	
	GraphList<char,bool> list;
		
	for(GNode<char, GraphList<char, T> * > * elem = head; elem != tail;elem = elem -> next){
		list.insertBegin(elem -> vertex, false);
	}
	
	
	while(!que.empty()){
		
		vertex = que.front();
		for(GNode<char, bool> * elem = list.head; elem != list.tail; elem = elem -> next){
			if(elem -> vertex == vertex){
				elem -> val = true;
				break;
			}
		}
		
		que.pop();
		cout << vertex << " ";
		
		for(GNode<char, GraphList<char, T> * > * elem = head; elem != tail;elem = elem -> next){
			if(elem -> vertex == vertex){
				
				for(GNode<char, T> * elem2 = elem -> val -> head; elem2 != elem -> val -> tail; elem2 = elem2 -> next){
					
					if(!list.search(elem2 -> vertex)){
						que.push(elem2 -> vertex);
						
						for(GNode<char, bool> * elem3 = list.head; elem3 != list.tail; elem3 = elem3 -> next){
							if(elem3 -> vertex == elem2 -> vertex){
								elem3 -> val = true;
								break;
							}
						}
					}
				}
				break;
			}
		}
	}
	cout << endl;
}


#endif /* GRAPH_H_ */