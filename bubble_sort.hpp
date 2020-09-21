#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include <iostream>
#include <vector>

using namespace std;




namespace bubbleSort
{


	template<class T>
	void swapp(T& va, T& vb){
	
		T temp = va;
		va = vb;
		vb = temp;
	}
	
	
	
	template<class T>
	void printVec(vector<T> vect){
	
		for(int i = 0; i < vect.size(); ++i){
			cout << vect[i] << " ";
		}
		cout << endl;
	}
	
	
	
	template<class T>
	vector<T> changeBubbleSort(vector<T> vect){
	
		bool change = true;
		int size = vect.size();
	
		do{
			change = false;
		
			for(int i = 0; i < size - 1; ++i){
				if(vect[i] > vect[i + 1]){
					swapp(vect[i], vect[i + 1]);
					change = true;
				}
			}
		}while(change);
	
		return vect;
	}
	
	
	
	template<class T>
	vector<T> pendulumBubbleSort(vector<T> vect){
		
		int size = vect.size() - 1;
		int i = 0, k = size;
		
		
		do{
			for(int j = i; j <= size; ++j){
				
				if(vect[j] > vect[j + 1]){
					swapp(vect[j], vect[j + 1]);
					k = j;
				}
			}
			size = k - 1;
			
			for(int j = size; j >= i; --j){
				
				if(vect[j] > vect[j + 1]){
					swapp(vect[j], vect[j + 1]);
					k = j;
				}
			}
			i = k + 1;
			
		}while(size - i > 0);
		
		
		return vect;
	}

}

#endif  /* BUBBLE_SORT_H_*/