#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;




template<class T>
class Stack{
public:
	Stack(){
		top = nullptr;
		size = 0;
	}
	bool isEmpty(void);
	void push(T value);
	void pop(void);
	void writesize();
	
private:
	Node<T> * top;
	int    size;
};




template<class T>
bool Stack<T>::isEmpty(void){
	return !size;
}


template<class T>
void Stack<T>::push(T value){
	if(!top){
		top = new Node<T>;
		top -> val = value;
		++size;
		return;
	}
	
	Node<T> * tmp = top;
	top = new Node<T>;
 	top -> next = tmp;
	top -> val = value;
	++size;
}

template<class T>
void Stack<T>::pop(void){
	if(isEmpty()){
		return;
	}
	
	Node<T> * tmp = top;
	top = top -> next;
	delete tmp;
	--size;
}

template<class T>
void Stack<T>::writesize(){
	cout << size << endl;
}


#endif /* STACK_H_ */