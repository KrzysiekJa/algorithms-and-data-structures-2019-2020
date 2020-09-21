#include <iostream>
#include <ctime>
#include <cstdlib>
#include "bubble_sort.hpp"
#include "comb_insert_shell_sort.hpp"




int main(void){
	srand(time(NULL));
	int length = 8;
	vector<int> vec;
	
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	
	std::cout << "Change Bubble Sort:" << std::endl;
	bubbleSort::printVec(vec);
	vec = bubbleSort::changeBubbleSort(vec);
	bubbleSort::printVec(vec);
	
	
	vec.clear();
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	
	std::cout << std::endl << "Pendulum Bubble Sort:" << std::endl;
	bubbleSort::printVec(vec);
	vec = bubbleSort::pendulumBubbleSort(vec);
	bubbleSort::printVec(vec);
	
	
	
	
	vec.clear();
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	
	std::cout << std::endl << "Comb Sort:" << std::endl;
	bubbleSort::printVec(vec);
	vec = comb_insert_shell_sort::combSort(vec);
	bubbleSort::printVec(vec);
	
	
	vector<int>::iterator iter1, iter2;
	iter1 = vec.begin();
	iter2 = vec.end();
	vec.erase(iter1, iter2);
	
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	
	std::cout << std::endl << "Insertion Sort:" << std::endl;
	bubbleSort::printVec(vec);
	vec = comb_insert_shell_sort::insertSort(vec);
	bubbleSort::printVec(vec);
	
	
	vec.clear();
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	
	std::cout << std::endl << "Selection Sort:" << std::endl;
	bubbleSort::printVec(vec);
	vec = comb_insert_shell_sort::selectionSort(vec);
	bubbleSort::printVec(vec);
	
	
	vec.clear();
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	
	std::cout << std::endl << "Knuth' Shell Sort:" << std::endl;
	bubbleSort::printVec(vec);
	vec = comb_insert_shell_sort::shellSortKnuth(vec);
	bubbleSort::printVec(vec);
}
