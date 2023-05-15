#include <iostream>
#include <string>
#include <vector>

using namespace std;

// forward declaration of BTnode class template`
template <typename valType>
class BTnode;

template <typename elemType>
class BinaryTree;

class string_BTnode {
public:
	// really dumb not using template
private:
	string _val;
	int _cnt;
	string_BTnode* _lchild;
	string_BTnode* _rchild;
};

// forward declaration of BTnode class template`
template <typename valType>
class BTnode {
	// friendship is one-way relationship
	friend BinaryTree<valType>;
public:
private:
	valType _val;
	int _cnt;
	BTnode* _lchild;
	BTnode* _rchild;
};

template <typename elemType>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(const BinaryTree& bt);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree& rhs);

	bool empty() const { 
		return _root == NULL; 
	}
	void clear();
private:
	// BTnode must be qualified with its template parameter list 
	BTnode<elemType>* _root;

	// copy a subtree addressed by src to tar
	void copy(BinaryTree<elemType>* tar, BTnode<elemType>* src);
};

int main(void)
{
	return 0;
}