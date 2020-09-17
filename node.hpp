#ifndef NODE_H_
#define NODE_H_


template<class Type>
class Node
{
	template<class T> friend class List;
	template<class T> friend class Queue;
	template<class T> friend class Stack;

public:
	Node(){
		next = nullptr;
	}
	
protected:
	Type val;
	Node<Type> * next;
};


#endif /* NODE_H_ */