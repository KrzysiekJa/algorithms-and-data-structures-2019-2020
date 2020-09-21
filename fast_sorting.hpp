#ifndef FAST_SORTING_H_
#define FAST_SORTING_H_

#include <iostream>
#include <vector>

using namespace std;




namespace DivideAndConquer
{


	template<class T>
	void swap(T& va, T& vb){
	
		T temp = va;
		va = vb;
		vb = temp;
	}
	
	
	
	template<class T>
	void printVec(vector<T> vect, int compared, int swaped){
		
		cout << "[ " ;
		for(int i = 0; i < vect.size(); ++i){
			cout << vect[i] << " ";
		}
		
		cout << "]" << endl;
		cout << vect.size() << " elements long" << endl;
		cout << "Number of comparison and swap operation: " << compared << " " << swaped << endl << endl;
	}
	
	
	
	template<class T>
	vector<T> merge(vector<T> vect, int left, int medium, int right, int & compared, int & swaped){
		
		int i, j, k;
		int len1 = medium - left + 1;
		int len2 = right - medium;
		
		T L[len1], R[len2];
		
		
		for(i = 0; i < len1; ++i){
			L[i] = vect[left + i];
		}
		for(j = 0; j < len2; ++j){
			R[j] = vect[medium + 1 + j];
		}
		
		i = 0; j = 0; k = left;
		
		
		while(i < len1 && j < len2){
			
			compared = compared + 3;
			
			if(L[i] <= R[j]){
				vect[k] = L[i];
				
				++swaped;
				++i;
			}else{
				vect[k] = R[j];
				
				++swaped;
				++j;
			}
			
			++k;
		}
		
		
		while(i < len1){
			vect[k] = L[i];
			
			++compared;
			++swaped;
			++i; ++k;
		}
		
		while(j < len2){
			vect[k] = R[j];
			
			++compared;
			++swaped;
			++j; ++k;
		}
		
		
		return vect;
	}
	
	
	
	template<class T>
	vector<T> mergeSortProcedure(vector<T> vect, int left, int right, int & compared, int & swaped){
	
		if(left < right){
			++compared;
			
			int medium = left + (right - left)/2;
			
			vect = mergeSortProcedure(vect, left, medium, compared, swaped);
			vect = mergeSortProcedure(vect, medium + 1, right, compared, swaped);
			
			vect = merge(vect, left, medium, right, compared, swaped);
		}
		
		
		return vect;
	}
	
	
	
	template<class T>
	vector<T> mergeSort(vector<T> vect, int & compared, int & swaped){
	
		return mergeSortProcedure(vect, 0, vect.size() - 1, compared, swaped);
	}
	
	
	
	template<class T>
	int partition(vector<T> &vect, int low, int high, int & compared, int & swaped){
		
		T pivot = vect[high];
		int i = low - 1;
		
		
		for(int j = low; j <= high - 1; ++j){
			
			if(vect[j] <= pivot){
				++i;
				swap(vect[i], vect[j]);
				++swaped;
			}
			++compared;
		}
		swap(vect[i + 1], vect[high]);
		++swaped;
		
		
		return i + 1;
	}
	
	
	
	template<class T>
	vector<T> quickSortProcedure(vector<T> vect, int low, int high, int & compared, int & swaped){
		
		if(low < high){
			++compared;
			
			int pivot = partition(vect, low, high, compared, swaped);
			
			vect = quickSortProcedure(vect, low, pivot - 1, compared, swaped);
			vect = quickSortProcedure(vect, pivot + 1, high, compared, swaped);
		}
		
		
		return vect;
	}
	
	
	
	template<class T>
	vector<T> quickSort(vector<T> vect, int & compared, int & swaped){
	
		return quickSortProcedure(vect, 0, vect.size() - 1, compared, swaped);
	}
	
}


#endif  /* FAST_SORTING_H_*/