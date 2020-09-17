#ifndef NODE_H_
#define NODE_H_


template<class Type1, class Type2>
class GNode
{
	template<class T> friend class Graph;
	template<class T1, class T2> friend class GraphList;
	
public:
	GNode(){
		next = nullptr;
	}
	
private:
	Type1 vertex;
	Type2 val;
	GNode<Type1, Type2> * next;
};


#endif /* NODE_H_ */