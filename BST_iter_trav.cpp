#include <iostream>
#include "BST_iter_trav_lib.hpp"




int main(void)
{
	BSTree<int> tree;
	
	tree.add(15);
	tree.add(6);
	tree.add(3);
	tree.add(2);
	tree.add(4);
	tree.add(7);
	tree.add(13);
	tree.add(9);
	tree.add(18);
	tree.add(17);
	tree.add(20);
	
	std::cout << "Iterative BST:" << endl << "Pre order: " << endl;
	tree.preOrder();
	std::cout << "In order: " << endl;
	tree.inOrder();
	std::cout << "Post order: " << endl;
	tree.postOrder();
}