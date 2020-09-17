#include <iostream>
#include <string>
#include "BSTree.hpp"




int main(void)
{
	BSTree<int> tree;
	
	tree.add(15);
	tree.add(6);
	tree.add(18);
	tree.add(3);
	tree.add(7);
	tree.add(17);
	tree.add(20);
	tree.add(2);
	tree.add(4);
	tree.add(13);
	tree.add(9);
	
	cout << "Tree pre order, in order, post order:" << endl;
	tree.printPreOrder();
	tree.printInOrder();
	tree.printPostOrder();
	
	cout << "Tree maximum: " << tree.max() << endl;
	cout << "Tree minumum: " << tree.min() << endl;
	
	cout << "Tree height: " << tree.height() << endl;
	cout << "7 node's to it's predeccessor path lenght: " << tree.lengthPredecc(7) << endl;
	
	cout << "Deleted:" << tree.del(7) << endl;
	cout << "Deleted:" << tree.del(20) << endl;
	tree.printInOrder();
	cout << "Tree height: " << tree.height() << endl;
}
