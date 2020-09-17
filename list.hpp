#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <fstream>
#include <cstdlib>
#include "node.hpp"

using namespace std;




template<class T>
class List
{
public:
	List(){
		tail = new Node<T>;
		head = tail;
		size = 0;
	}
	~List(){
		delete tail;
	}
	
	void insertBegin(T value);
	void print();
	T search(T value);
	void deleteThis(T value);
	void loadFromFile(string fileName);
	void saveToFile(string fileName);
	
private:
	Node<T> * head;
	Node<T> * tail;
	int    size;
};




template<class T>
void List<T>::insertBegin(T value){
	
	Node<T> * temp = new Node<T>;
	
	temp -> val  = value;
	temp -> next = head;
	++size;
	head = temp;
}


template<class T>
void List<T>::print(){
	
	if(head == tail){
		cout << "Empty." << endl;
	}
	
	for(Node<T> * elem = head; elem != tail;elem = elem -> next){
		cout << elem -> val << " ";
	}
	cout << endl;
}


template<class T>
T List<T>::search(T value){
	
	Node<T> * elem = head;
	while(elem && elem -> val != value){
		elem = elem -> next;
	}
	
	if (elem == nullptr){
		throw "No such element";
	}
	return elem -> val;
}


template<class T>
void List<T>::deleteThis(T value){
	
	Node<T> * elem = head, * previev = nullptr;
	for(;elem && elem -> val != value; previev = elem, elem = elem -> next);
	
	if(!previev){
		head = head -> next;
	}
	else{
		previev -> next = elem -> next;
	}
	--size;
	delete elem;
}


template<class T>
void List<T>::loadFromFile(string fileName){
	ifstream file;
	string   line;
	
	file.open(fileName, ios::in);
	if(file.good() == false){
		return;
	}
	
	while(!file.eof()){
		getline(file,line);
		insertBegin(atoi(line.c_str()));
	}
	
	file.close();
}


template<class T>
void List<T>::saveToFile(string fileName){
	ofstream file;
	Node<T> * elem = head;
	
	file.open(fileName, ios::out);
	if(file.good() == false){
		return;
	}
	
	while(elem != tail){
		file << elem -> val << "\t";
		elem = elem -> next;
	}
	
	file.close();
}

#endif /* LIST_H_ */
