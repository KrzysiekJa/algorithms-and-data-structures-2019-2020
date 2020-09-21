#include <ctime>
#include <cstdlib>
#include <vector>
#include "fast_sorting.hpp"





int main(void){
	srand(time(NULL));
	
	vector<int> vec;
	int length = 20;
	int compared = 0, swapped = 0;
	
	
	
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	DivideAndConquer::printVec(vec, compared, swapped);
	vec = DivideAndConquer::mergeSort(vec, compared, swapped);
	cout << "**Merge sort :**" << endl;
	DivideAndConquer::printVec(vec, compared, swapped);
	
	compared = 0, swapped = 0;
	vec.clear();
	
	
	
	for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	DivideAndConquer::printVec(vec, compared, swapped);
	vec = DivideAndConquer::quickSort(vec, compared, swapped);
	cout << "**Quick sort :**" << endl;
	DivideAndConquer::printVec(vec, compared, swapped);
	
	compared = 0, swapped = 0;	
	vector<int>::iterator iter1, iter2;
	iter1 = vec.begin();
	iter2 = vec.end();
	vec.erase(iter1, iter2);
	
	
	
	/*for(int i = 0; i < length; ++i){
		vec.push_back(static_cast<int>(rand() % 99 + 1));
	}
	
	DivideAndConquer::printVec(vec, compared, swapped);
	vec = DivideAndConquer::mergeSort(vec, compared, swapped);
	cout << "Merge sort :" << endl;
	DivideAndConquer::printVec(vec, compared, swapped);
	
	vec.clear();
	delete vec;*/
}
