#ifndef TREENODE_H_
#define TREENODE_H_



template<class Type>
class TNode
{
	template<class T> friend class BSTree;
	
public:
	TNode(){
		parent = nullptr;
		left   = nullptr;
		right  = nullptr;
	}
	
private:
	Type val;
	TNode<Type> * parent;
	TNode<Type> * left;
	TNode<Type> * right;
};


#endif /* TREENODE_H_ */