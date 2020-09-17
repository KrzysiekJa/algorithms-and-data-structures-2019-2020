#include <iostream>
#include "stack.hpp"

using namespace std;




int main(void)
{
	Stack<int> stack;
	
	stack.push(3);
	stack.push(5);
	stack.push(67);
	cout << "Is empty: " << stack.isEmpty() << endl << endl;
	stack.pop();
	cout << "Size: ";
	stack.writesize();
	cout << endl;
	stack.push(55);
	cout << "Size: ";
	stack.writesize();
	cout << endl;
	stack.pop();
	stack.pop();
	stack.pop();
	cout << "Is empty: " << stack.isEmpty() << endl;
}
