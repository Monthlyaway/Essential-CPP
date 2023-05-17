#include <iostream>
#include <string>
#include <vector>

using namespace std;

// forward declaration of BTnode class template`
template <typename elemType>
class BTnode;

template <typename elemType>
class BinaryTree;

// forward declaration of BTnode class template`
template <typename elemType>
class BTnode {
	// friendship is one-way relationship
	friend BinaryTree<elemType>;
public:
	BTnode(const elemType& val);
	void insert_value(const elemType& nval);
	void remove_value(const elemType& val, BTnode*& prev);
	void lchild_leaf(BTnode* leaf, BTnode* subtree);
private:
	elemType _val;
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
	void clear() {
		if (_root) {
			clear(_root);
			_root = NULL;
		}
	}
	void insert(const elemType& nval);
	void remove(const elemType& val);
	void remove_root();
private:
	// BTnode must be qualified with its template parameter list 
	BTnode<elemType>* _root;

	// copy a subtree addressed by src to tar
	void copy(BTnode<elemType>* tar, BTnode<elemType>* src);
};

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree() : _root(0) {}

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs) {
	copy(_root, rhs._root);
}

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree() {
	clear();
}

template <typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::operator=(const BinaryTree& rhs) {
	if (this != &rhs) {
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

template <typename elemType>
inline BTnode<elemType>::BTnode(const elemType& val) :
	_val(val), _cnt(0), _lchild(NULL), _rchild(NULL) {
	/*
	* if I write _val = val in the constructor body instead of list initialization
	* the two steps will involve:
	* 1. default constructor of _val
	* 2. copy assignment constrctor (AKA overload of operator=)
	*/
}

template <typename elemType>
inline void BinaryTree<elemType>::insert(const elemType& nval) {
	if (empty()) {
		_root = new BTnode<elemType>(nval);
	}
	else {
		_root->insert_value(nval);
	}
}

template <typename elemType>
void BTnode<elemType>::insert_value(const elemType& nval) {
	// recursion insert
	if (nval == _val)
		_cnt++;
	else if (nval < _val)
		if (!_lchild)
			_lchild = new BTnode<elemType>(nval);
		else
			_lchild->insert_value(nval);
	else
		if (!_rchild)
			_rchild = new BTnode<elemType>(nval);
		else
			_rchild->insert_value(nval);

}

template <typename elemType>
void BinaryTree<elemType>::remove(const elemType& val) {
	if (_root) {
		if (_root->_val == val)
			remove_root();
		else {
			_root->remove_value(val, _root);
		}
	}
}

template <typename elemType>
void BinaryTree<elemType>::remove_root() {
	if (!_root)
		return;
	BTnode<elemType>* tmp = _root;  // store the value of _root as it is modified lately
	if (_root->_rchild) {
		_root = _root->_rchild;
		// attach the left child to the bottom of the right child's left subtree
		if (tmp->_lchild) {
			BTnode<elemType>* origin_lc = tmp->_lchild;
			BTnode<elemType>* new_lc = _root->_lchild;
			if (!new_lc)
				_root->_lchild = origin_lc;
			// lchild_leaf will travel through the tree from subtree
			// and make leaf attach to the right position
			else
				BTnode<elemType>::lchild_leaf(origin_lc, new_lc);
		}
	}
	else
		_root = _root->_lchild;
	// remove the node previously root
	delete tmp;

}

template <typename elemType>
void BTnode<elemType>::lchild_leaf(BTnode* leaf, BTnode* subtree) {
	while (subtree->_lchild)
		subtree = subtree->_lchild;
	subtree->_lchild = leaf;
}

template <typename elemType>
void BTnode<elemType>::remove_value(const elemType& val, BTnode*& prev) {
	if (val < _val) {
		if (!_lchild)  // not present
			return;
		_lchild->remove_value(val, _lchild);
	}
	else if (val > _val) {
		if (!_rchild)  // not present
			return;
		_rchild->remove_value(val, _rchild);
	}
	else {
		// ok, found it, reset the tree, then delete the node
		if (_rchild) {
			prev = _rchild;
			if (_lchild) {
				lchild_leaf(_lchild, _rchild->_lchild);
			}
		}
		else
			prev = _lchild;
		delete this;
	}
}




int main(void)
{
	return 0;
}