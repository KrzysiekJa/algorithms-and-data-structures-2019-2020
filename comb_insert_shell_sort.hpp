#ifndef COMBSORT_H_
#define COMBSORT_H_

#include <iostream>
#include <vector>

using namespace std;




namespace comb_insert_shell_sort
{	
	
	
	template<class T>
	void swap(T& va, T& vb){
	
		T temp = va;
		va = vb;
		vb = temp;
	}
	
	
	
	int newGap(int gap){
		
		gap = gap * 10 / 13;
		
		if(gap == 9 || gap == 10){
			gap = 11;
		}
		if(gap == 0){
			gap = 1;
		}
		
		return gap;
	}
	
	
	
	template<class T>
	vector<T> combSort(vector<T> vect){
		
		int size = vect.size();
		int gap  = vect.size();
		bool swaped = true;
		
		while(gap > 1 || swaped){
			gap = newGap(gap);
			swaped = false;
			
			for(int i = 0; i + gap < size; ++i){
				if(vect[i + gap] < vect[i]){
					
					swap(vect[i + gap], vect[i]);
					swaped = true;
				}
			}
		}
		
		return vect;
	}
	
	
	
	template<class T>
	vector<T> insertSort(vector<T> vect){
		
		int size = vect.size();
		int j;
		T temp;
		
		for(int i = 1; i < size; ++i){
			temp = vect[i];
			j = i - 1;
			
			while(j >= 0 && vect[j] > temp){
				vect[j+1] = vect[j];
				--j;
			}
			vect[j+1] = temp;
		}
		
		return vect;
	}
	
	
	
	template<class T>
	int maxElement(vector<T> vect, int size){
		
		int max = 0;
		
		for(int i = 1; i < size; ++i){
			if(vect[i] > vect[max]){
				max = i;
			}
		}
		
		return max;
	}
	
	
	
	template<class T>
	vector<T> selectionSort(vector<T> vect){
		
		for(int i = vect.size(); i >= 2; --i){
			int max = maxElement(vect, i);
			
			if(max != i - 1){
				swap(vect[i-1], vect[max]);
			}
		}
		
		return vect;
	}
	
	
	
	template<class T>
	vector<T> shellSortKnuth(vector<T> vect){
		
		int size = vect.size();
		T temp;
		int h, j;
		
		for(h = 1; h < size; h = 3 * h + 1){}
			h /= 9;
			
		if(!h){
			++h;
		}
		
		
		while(h){
			for(int i = size - h - 1; i >= 0; --i){
				
				temp = vect[i];
				j = i + h;
				while((j < size) && (temp > vect[j])){
					vect[j - h] = vect[j];
					j+=h;
				}
				vect[j - h] = temp;
			}
			h /= 3;
		}
		
		return vect;
	}

}


#endif  /* COMBSORT_H_ */