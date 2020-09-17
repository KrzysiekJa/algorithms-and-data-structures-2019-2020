#include <iostream>
#include "stack_table.hpp"

using namespace std;




int main(void)
{
	StackTab<int> stack(4);
	
	stack.push(3);
	stack.push(5);
	stack.push(67);
	stack.push(3);
	stack.push(21);
	cout << stack.isEmpty() << endl;
	
	cout << stack.pop() << endl;
	stack.push(55);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.isEmpty() << endl;;
}
