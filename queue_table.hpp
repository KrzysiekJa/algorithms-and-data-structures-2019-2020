#ifndef QUEUE_TABLE_H_
#define QUEUE_TABLE_H_

#include <iostream>
#include <string>
// queue, which using talbe to work
using namespace std;




template<class T>
class QueueTab{
public:
	QueueTab(int Nsize): size(Nsize){
		table = new T[size];
		front = 0;
		tail  = size - 1;
	}
	~QueueTab(){
		delete [] table;
	}
	
	bool isEmpty(void);
	bool isFull(void);
	void insert(T value);
	T    deleteFront(void);
	
private:
	T * table;
	int front;
	int tail;
	const int size;
	
	int  addNext(int value);
};




template<class T>
int  QueueTab<T>::addNext(int value){
	
	return((value + 1)% size);
}

template<class T>
bool QueueTab<T>::isEmpty(void){
	
	return (addNext(tail) == front);
}

template<class T>
bool QueueTab<T>::isFull(void){
	
	return (addNext(addNext(tail)) == front);
}

template<class T>
void QueueTab<T>::insert(T value){
	if(!isFull()){
		tail = addNext(tail);
		table[tail] = value;
	}
}

template<class T>
T QueueTab<T>::deleteFront(void){
	if(!isEmpty()){
		T val = table[front];
		front = addNext(front);
		
		return val;
	}
}


#endif /* QUEUE_TABLE_H_ */