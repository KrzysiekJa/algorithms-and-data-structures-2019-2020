#ifndef BSTREEITER_H_
#define BSTREEITER_H_

#include <iostream>
#include <string>
#include "node.hpp"
#include "tree_node.hpp"

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
	T    pop(void);
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
T Stack<T>::pop(void){
	if(isEmpty()){
		return nullptr;
	}
	
	Node<T> * tmp = top;
	top = top -> next;
	--size;
	
	return tmp -> val;
}

template<class T>
void Stack<T>::writesize(){
	cout << size << endl;
}




template<class T>
class BSTree
{
public:
	BSTree(){
		root = new TNode<T>;
		root = nullptr;
	}
	
	void add(T value);
	void preOrder(void);
	void inOrder(void);
	void postOrder(void);
	
private:
	TNode<T> * root;
	
	TNode<T> * insert(TNode<T> * node, T value);
	void printPreOrder(TNode<T> * node);
	void printInOrder(TNode<T> * node);
	void printPostOrder(TNode<T> * node);
};




template<class T>
TNode<T> * BSTree<T>::insert(TNode<T> * node, T value){
	
	if(node == nullptr){
		node = new TNode<T>;
		node->val = value;
	}
	else if(node->val < value){
		node->right = insert(node->right, value);
		node->right -> parent = node;
	}
	else{
		node->left = insert(node->left, value);
		node->left -> parent = node;
	}
	
	return node;
}

template<class T>
void BSTree<T>::add(T value){
	
	root = insert(root, value);
}


template<class T>
void BSTree<T>::printPreOrder(TNode<T> * node){
	
	if(node == nullptr){
		return;
	}
	
	Stack<TNode<T> *> stack;
	stack.push(node);
	
	
	while(stack.isEmpty() == false){
		node = stack.pop();
		cout << node -> val << " ";
				
		if(node->right){
			stack.push(node->right);
		}
		if(node->left){
			stack.push(node->left);
		}
	}
	cout << endl;
}

template<class T>
void BSTree<T>::printInOrder(TNode<T> * node){
	
	if(node == nullptr){
		return;
	}
	
	Stack<TNode<T> *> stack;
	TNode<T> * current = node;
	
	while(current != nullptr || stack.isEmpty() == false){
		while(current != nullptr){
			stack.push(current);
			current = current -> left;
		}
		current = stack.pop();
		cout << current -> val << " ";
		current = current -> right;
	}
	cout << endl;
}

template<class T>
void BSTree<T>::printPostOrder(TNode<T> * node){
	
	if(node == nullptr){
		return;
	}
	
	Stack<TNode<T> *> stack1, stack2;
	stack1.push(node);
	TNode<T> * current;
	
	
	while(stack1.isEmpty() == false){
		current = stack1.pop();
		stack2.push(current);
		
		if(current->left){
			stack1.push(current->left);
		}
		if(current->right){
			stack1.push(current->right);
		}
	}
	
	while(stack2.isEmpty() == false){
		current = stack2.pop();
		cout << current -> val << " ";
	}	
	cout << endl;
}


template<class T>
void BSTree<T>::preOrder(void){
	printPreOrder(root);
}

template<class T>
void BSTree<T>::inOrder(void){
	printInOrder(root);
}

template<class T>
void BSTree<T>::postOrder(void){
	printPostOrder(root);
}


#endif  /* BSTREEITER_H_ */