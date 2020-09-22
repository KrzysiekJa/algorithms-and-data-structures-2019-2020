#include <iostream>
#include <limits.h> 
#include <vector>
#include <queue>
#include <string>




namespace greddy_dynamic
{
	template<class T>
	T MatrixChainOrder(std::vector<T> dims){
		
		int n = dims.size() - 1;
		int j;
		T cost = 0;
		int m[n][n];
		
		
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= n; ++j){
				m[i][j] = 0;
			}
		}
		
		
		for(int len = 1; len < n ; ++len){
			
			for(int i = 0; i < n - len; ++i){
				j = i + len;
				m[i][j] = INT_MAX;
				
				for(int k = i; k <= j; ++k){
					cost = m[i][k] + m[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
					
					if(cost < m[i][j]){
						m[i][j] = cost;
						
					}
				}
			}
		}
		
		return cost;
	}
	
	
	
	template<class T1, class T2>
	struct HeapNode
	{
		
		T1 data1;
		T2 data2;
		
		HeapNode * left, * right;
		
		HeapNode(T1 data1, T2 data2);
	};
	
	template<class T1, class T2>
	HeapNode<T1, T2>::HeapNode(T1 data1, T2 data2){
		left  = nullptr;
		right = nullptr;
		this -> data1 = data1;
		this -> data2 = data2;
	}
	
	
	
	template<class T1, class T2>
	struct Compare
	{
		bool operator()(HeapNode<T1, T2> * left, HeapNode<T1, T2> * right){
			return (left -> data2 > right -> data2);
		}
	};
	
	
	
	template<class T1, class T2>
	void print(struct HeapNode<T1, T2> * node, std::string str){
		
		if(!node){
			return;
		}
		
		if(node -> data1 != '$'){
			std::cout << node -> data1 << ": " << str << std::endl;
		}
		
		print(node -> left , str + "0");
		print(node -> right, str + "1");
	}
	
	
	template<class T1, class T2>
	void funHuffmanCodes(std::vector<T1> data1, std::vector<T2> data2){
		struct HeapNode<T1, T2> * left, * right, * top;
		
		std::priority_queue<HeapNode<T1, T2> *, std::vector<HeapNode<T1, T2> *>, Compare<T1, T2> > heap;
		
		for(int i = 0; i > data1.size(); ++i){
			heap.push(new HeapNode<T1, T2>(data1[i], data2[i]));
		}
		
		
		while(heap.size() != 1){
			
			left = heap.top();
			heap.pop();
			
			right = heap.top();
			heap.pop();
			
			
			top = new HeapNode<T1, T2>('$', left -> data2 + right -> data2);
			
			top -> left  = left;
			top -> right = right;
			
			heap.push(top);
		}
		
		print(heap.top(), "");
	}
}
