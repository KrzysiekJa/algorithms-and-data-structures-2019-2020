#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;




template<class T>
class Queue{
public:
	Queue(){
		head = nullptr;
		tail = head;
		size = 0;
	}
	
	bool isEmpty(void);
	void insert(T value);
	T  deleteFirst(void);
	void writesize();
	
private:
	Node<T> * head;
	Node<T> * tail;
	int    size;
};




template<class T>
bool Queue<T>::isEmpty(void){
	
	if(size == 0){
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void Queue<T>::insert(T value){
	
	if(!head){
		head = new Node<T>;
		head -> val = value;
		tail = head;
		++size;
		return;
	}
	
	tail -> next = new Node<T>;
 	tail = tail -> next;
	tail -> val = value;
	++size;
}

template<class T>
T Queue<T>::deleteFirst(void){
	
	T el_int = head -> val;
	Node<T> * elem = head;
	
	head = head -> next;
	delete elem;
	--size;
	
	return el_int;
}

template<class T>
void Queue<T>::writesize(){
	cout << size << endl;
}


#endif /* QUEUE_H_ */