#include <iostream>
#include "queue_table.hpp"

using namespace std;




int main(void)
{
	QueueTab<int> que(4);
	
	que.insert(3);
	que.insert(5);
	que.insert(91);
	que.insert(23);
	
	cout << que.isEmpty() << endl;
	cout << que.deleteFront() << endl;
	que.insert(55);
	
	cout << que.isFull() << endl;
	cout << que.deleteFront() << endl;
	cout << que.deleteFront() << endl;
	cout << que.deleteFront() << endl;
	que.insert(41);
	cout << que.deleteFront() << endl;
	cout << que.isEmpty() << endl;
}
