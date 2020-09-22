#include <iostream>
#include <vector>
#include "greddy_dynamic.hpp"



int main(void)
{
	std::vector<int> chain;
	std::vector<int>   freq;
	std::vector<char>  data;
	
	chain.push_back(3);
	chain.push_back(4);
	chain.push_back(5);
	chain.push_back(1);
	chain.push_back(2);
	chain.push_back(7);
	
	int result = greddy_dynamic::MatrixChainOrder(chain);
	
	std::cout << result << std::endl;
	
	
	
	char tab1[] = { 'a', 'b', 'c', 'w', 'x', 'y', 'z' };
	int  tab2[] = { 4, 9, 11, 20, 26, 30, 36 };
	
	for(char i : tab1){
		data.push_back(i);
	}
	for(int i : tab1){
		freq.push_back(i);
	}
	
	greddy_dynamic::funHuffmanCodes(data, freq);
}