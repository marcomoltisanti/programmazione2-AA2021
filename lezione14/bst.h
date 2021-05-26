#ifndef BST_H
#define BST_H

#include "node_bst.h"

using namespace std;

template<class T>
class BST {
	NodeBST<T> *root;
	
	void inorder(NodeBST<T> * n) {
		if(n == NULL)
			return;
		this->inorder(n->getLeft());
		cout << *n << endl;
		this->inorder(n->getRight());
	}

	NodeBST<T> *search(NodeBST<T> *n, T key) {
		if(n == NULL)
			return NULL;
		else if(n->getKey() == key)
			return n;
		else if(key <= n->getKey())
			return this->search(n->getLeft(), key);
		else if(key >= n->getKey())
			return this->search(n->getRight(), key);
		
		return NULL;
	}

	public:
	BST() : root(NULL) {}
	
	//inorder
	void inorder() {
		this->inorder(this->root);
	}

	//search
	NodeBST<T> *search(T key) {
//		NodeBST<T> * n = new NodeBST<T>(key);
		return this->search(this->root, key);
	}

	//predecessor
	//successor
	//min
	//max
	//insert
	void insert(T key) {
		if(root == NULL) {
			root = new NodeBST<T>(key);
			return;
		}
		
		NodeBST<T> * ptr = root;
		NodeBST<T> * parent = NULL;
		while(ptr != NULL) {
			
			parent = ptr;
			if(key <= ptr->getKey()) {
				ptr = ptr->getLeft();
			}
			else if (key >= ptr->getKey()) {
				ptr = ptr->getRight();
			}
		}
		
		NodeBST<T> * toInsert = new NodeBST<T>(key);
		if(key <= parent->getKey()) {
			parent->setLeft(toInsert);
		}
		else if(key >= parent->getKey()) {
			parent->setRight(toInsert);
		}
		
		toInsert->setParent(parent);
			
	
	}
};
#endif
