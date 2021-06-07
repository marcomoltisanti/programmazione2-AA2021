#include "node_bst.h"
#include "bst.h"
#include <cstdlib>


int main() {
	/*
	NodeBST<int> n(10);
	NodeBST<int> n1(107);
	NodeBST<int> n2(120);

	cout << n1 << endl;
	cout << n2 << endl;
	cout << n << endl;
	*/

	BST<int> tree;
	tree.insert(102);
	//BST<int> tree_deg;
	srand(0);

	for(int i=0; i < 20; i++) {
		tree.insert(rand() % 201);
	}

	tree.inorder();
	//tree_deg.inorder();
	cout << "Predecessor e successor" << endl;
	cout << *(tree.predecessor(tree.search(97))) << endl;
	cout << *(tree.predecessor(tree.search(143))) << endl;
	cout << *(tree.successor(tree.search(143))) << endl;
	cout << *(tree.successor(tree.search(82))) << endl;

	tree.deleteNode(tree.search(102));
	tree.deleteNode(tree.search(7));
	tree.deleteNode(tree.search(134));

	cout << "Inorder dopo cancellazione" << endl;
	tree.inorder();
	cout << "Preorder dopo cancellazione" << endl;
	tree.preorder();
	cout << "Postorder dopo cancellazione" << endl;
	tree.postorder();	
}
