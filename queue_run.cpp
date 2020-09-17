#include <iostream>
#include "queue.hpp"

using namespace std;




int main(void)
{
	Queue<int> que;
	
	que.insert(3);
	que.insert(5);
	que.insert(67);
	que.isEmpty();
	cout << que.deleteFirst() << endl << "Size: ";
	que.writesize();
	cout << endl;
	que.insert(55);
	cout << que.deleteFirst() << endl;
	cout << que.deleteFirst() << endl;
	cout << que.deleteFirst() << endl;
	cout << endl << "Empty: " << que.isEmpty() << endl;
}
