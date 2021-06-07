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

	void preorder(NodeBST<T> * n) {
		if(n == NULL)
			return;
		cout << *n << endl;
		this->preorder(n->getLeft());
		this->preorder(n->getRight());
	}

	void postorder(NodeBST<T> * n) {
		if(n == NULL)
			return;
		this->postorder(n->getLeft());
		this->postorder(n->getRight());
		cout << *n << endl;
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


	//preorder
	void preorder() {
		this->preorder(this->root);
	}
	//inorder
	void postorder() {
		this->postorder(this->root);
	}

	//search
	NodeBST<T> *search(T key) {
//		NodeBST<T> * n = new NodeBST<T>(key);
		return this->search(this->root, key);
	}

	//predecessor
	NodeBST<T> *predecessor(NodeBST<T> * x) {
		NodeBST<T> * ptr = x;
		if(x->getLeft() != NULL) {
			ptr = x->getLeft();
			while(ptr->getRight() != NULL) 
				ptr = ptr->getRight();
			return ptr;	
		}
		else {
			NodeBST<T> *y = ptr->getParent();
			while(ptr == y->getLeft()) {
				ptr = y;
				y = y->getParent();
			}
			return y;
		}
		
		return NULL;
	}
	//successor
	
	NodeBST<T> *successor(NodeBST<T> * x) {
		NodeBST<T> * ptr = x;
		if(x->getRight() != NULL) {
			ptr = x->getRight();
			while(ptr->getLeft() != NULL)
				ptr = ptr->getLeft();
			return ptr;
		}
		else {
			NodeBST<T> *y = ptr->getParent();
			while(ptr == y->getRight()) {
				ptr = y;
				y = y->getParent();
			}
			return y;
		}

		return NULL;
	}
	//min
	NodeBST<T> *min() {
		if(root == NULL)
			return NULL;

		NodeBST<T> *ptr = root;
		while(ptr->getLeft() != NULL) {
			ptr = ptr->getLeft();
		}
		return ptr;
	}
	//max
	NodeBST<T> *max() {
		if(root == NULL)
			return NULL;
		NodeBST<T> *ptr = root;
		while(ptr->getRight() != NULL) {
			ptr = ptr->getRight();
		}
		return ptr;
	}
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
	//delete
	NodeBST<T> * deleteNode(NodeBST<T> * x) {
		if(x == NULL || root == NULL)
			return NULL;
		// 1. x è una foglia
		if(x->getLeft() == NULL && x->getRight() == NULL) {
			NodeBST<T> * y = x->getParent();
			if(x == y->getLeft())
				y->setLeft(NULL);
			else
				y->setRight(NULL);
		}
		// 2. x ha solo un figlio
		else if(x->getLeft() == NULL || x->getRight() == NULL) {
			//semplificare questa selezione
			if(x->getLeft() != NULL) {
				if(x == x->getParent()->getLeft())
					x->getParent()->setLeft(x->getLeft());
				else
					x->getParent()->setRight(x->getLeft());
			}
			else {
				if(x == x->getParent()->getLeft())
					x->getParent()->setLeft(x->getRight()); 
				else
					x->getParent()->setRight(x->getRight());
			}
		}
		// 3. x ha due figli
		else {
			NodeBST<T> * z = this->successor(x);
			cout << "successore: " << *z << endl;
			//NodeBST<T> *tmp = new NodeBST<T>(x->getKey());
			x->setKey(z->getKey());
			cout << "x = " << *x << endl;

				//attaccare il figlio destro di z come figlio sinistro del padre di z
				if(z == z->getParent()->getLeft()) {
					cout << "z sx" << endl; z->getParent()->setLeft(z->getRight());}
				else {cout << "z dx" << endl; z->getParent()->setRight(z->getRight());}
			delete z;
			//return tmp;
		}

		return x;
	}
};
#endif
