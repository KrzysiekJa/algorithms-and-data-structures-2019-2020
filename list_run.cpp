#include <iostream>
#include "list.hpp"



int main(void)
{
	List<int> list;
	
	list.insertBegin(3);
	list.insertBegin(5);
	list.insertBegin(67);
	list.deleteThis(5);
	try{
		std::cout << list.search(3) << std::endl;
		std::cout << list.search(5) << std::endl;
	} catch(...){
		cout << "Error." << endl;
	}
	list.insertBegin(55);
	list.print();
	
	list.loadFromFile("numbers.txt");
	list.print();
	list.saveToFile("new.txt");
}
