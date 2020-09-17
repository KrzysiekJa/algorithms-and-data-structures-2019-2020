#ifndef STACK_TABLE_H_
#define STACK_TABLE_H_

#include <iostream>
#include <string>

using namespace std;




template<class T>
class StackTab{
public:
	StackTab(int Nsize): size(Nsize){
		table = new T[size];
		top   = nullptr;
	}
	~StackTab(){
		delete [] table;
	}
	
	bool isFull(void);
	bool isEmpty(void);
	void push(T value);
	T	 pop(void);
	
private:
	T * top;
	T * table;
	const int size;
};




template<class T>
bool StackTab<T>::isFull(void){
	if(top == &table[size]){
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool StackTab<T>::isEmpty(void){
	if(top == nullptr){
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void StackTab<T>::push(T value){
	if(top == &table[size]){
		return;
	}
	if(top == nullptr){
		top = table;
		table[0] = value;
	}
	++top;
	* top = value;
}

template<class T>
T StackTab<T>::pop(void){
	if(isEmpty()){
		return false;
	}
	
	T val = * top;
	--top;
	
	return val;
}


#endif /* STACK_TABLE_H_ */