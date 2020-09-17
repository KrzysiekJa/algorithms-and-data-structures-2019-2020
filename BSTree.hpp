#ifndef BSTREE_H_
#define BSTREE_H_

#include "tree_node.hpp"

using namespace std;




template<class T>
class BSTree
{
public:
	BSTree(){
		root = nullptr;
	}
	
	void add(T value);
	void printPreOrder(void);
	void printInOrder(void);
	void printPostOrder(void);
	T min(void);
	T max(void);
	T del(T value);
	int height(void);
	int lengthPredecc(T value);
	
private:
	TNode<T> * root;
	
	TNode<T> * insert(TNode<T> * node, T value);
	TNode<T> * search(TNode<T> * node,T key);
	TNode<T> * successor(TNode<T> * node);
	TNode<T> * predeccessor(TNode<T> * node);
	TNode<T> * delNode(TNode<T> * node, T key);
	TNode<T> * minNode(TNode<T> * node);
	TNode<T> * maxNode(TNode<T> * node);
	int heightNode(TNode<T> * node);
	int lengthNode(TNode<T> * node);
	void preOrder(TNode<T> * node);
	void inOrder(TNode<T> * node);
	void postOrder(TNode<T> * node);
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
void BSTree<T>::preOrder(TNode<T> * node){
	if(node == nullptr){
		return;
	}
	
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}


template<class T>
void BSTree<T>::inOrder(TNode<T> * node){
	if(node == nullptr){
		return;
	}
	
	inOrder(node->left);
	cout << node->val << " ";
	inOrder(node->right);
}


template<class T>
void BSTree<T>::postOrder(TNode<T> * node){
	if(node == nullptr){
		return;
	}
	
	postOrder(node->left);
	postOrder(node->right);
	cout << node->val << " ";
}


template<class T>
void BSTree<T>::printPreOrder(void){
	preOrder(root);
	cout << endl;
}


template<class T>
void BSTree<T>::printInOrder(void){
	inOrder(root);
	cout << endl;
}


template<class T>
void BSTree<T>::printPostOrder(void){
	postOrder(root);
	cout << endl;
}


template<class T>
T BSTree<T>::min(void){
	
	TNode<T> * node = minNode(root);
	
	return node -> val;
}


template<class T>
T BSTree<T>::max(void){
	
	TNode<T> * node = maxNode(root);
	
	return node -> val;
}


template<class T>
TNode<T> * BSTree<T>::minNode(TNode<T> * node){
	
	while(node -> left){
		node = node -> left;
	}
	
	return node;
}


template<class T>
TNode<T> * BSTree<T>::maxNode(TNode<T> * node){
	
	while(node -> right){
		node = node -> right;
	}
	
	return node;
}


template<class T>
TNode<T> * BSTree<T>::successor(TNode<T> * node){
	if(node -> right){
		return minNode(node -> right);
	}
	TNode<T> * succ_node = node -> parent;
	
	while(succ_node && (node == succ_node -> right)){
		node      = succ_node;
		succ_node = succ_node -> parent;
	}
	
	return succ_node;
}


template<class T>
TNode<T> * BSTree<T>::predeccessor(TNode<T> * node){
	if(node -> left){
		return maxNode(node -> left);
	}
	
	TNode<T> * new_node = node -> parent;
	
	while(new_node && node == new_node -> left){
		node = new_node;
		new_node = new_node -> parent;
	}
	
	return new_node;
}


template<class T>
TNode<T> * BSTree<T>::search(TNode<T> * node, T key){
	
	if(node || node -> val == key){
		return node;
	}
	if(key < node -> val){
		return search(node -> left, key);
	}else{
		return search(node -> right, key);
	}
}


template<class T>
TNode<T> * BSTree<T>::delNode(TNode<T> * node, T key){
	
	if(node == nullptr){
		return node;
	}
	
	if(key < node -> val){
		node -> left = delNode(node -> left, key);
		return node;
	}
	else if(key > node -> val){
		node -> right = delNode(node -> right, key);
		return node;
	}
	
	if(node -> left == nullptr){
		TNode<T> * temp = node -> right;
		delete node;
		return temp;
	}
	else if(node -> right == nullptr){
		TNode<T> * temp = node -> left;
		delete node;
		return temp;
	}
	else{
		
		TNode<T> * succ = successor(node);
		
		TNode<T> * succ_parent = succ -> parent;
		succ_parent -> left = succ -> right;
		node -> val = succ -> val;
		
		return node;
	}
}


template<class T>
T BSTree<T>::del(T value){
	
	if(root == nullptr){
		return -1;
	}
	
	TNode<T> * node = delNode(root, value);
	
	return node -> val;
}


template<class T>
int BSTree<T>::heightNode(TNode<T> * node){
	
	if(!node){
		return 0;
	}
	
	int lval = 0, rval = 0;
	
	lval = heightNode(node -> left);
	rval = heightNode(node -> right);
	
	if(lval >= rval){
		return (lval + 1);
	} else {
		return (rval + 1);
	}
}


template<class T>
int BSTree<T>::height(void){
	
	int lval = 0, rval = 0;
	
	lval = heightNode(root -> left);
	rval = heightNode(root -> right);
	
	if(lval >= rval){
		return (lval);
	} else {
		return (rval);
	}
}


template<class T>
int  BSTree<T>::lengthNode(TNode<T> * node){
	
	if(node == nullptr){
		return 0;
	}
	
	int left  = lengthNode(node -> left);
	int right = lengthNode(node -> left);
	
	if(left > right){
		return right + 1;
	}
	else{
		return left + 1;
	}
}


template<class T>
int BSTree<T>::lengthPredecc(T value){
	
	TNode<T> * predecc = predeccessor(search(root, value));
	
	return lengthNode(predecc);
}


#endif  /* BSTREE_H_ */