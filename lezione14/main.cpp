#include "node_bst.h"
#include "bst.h"
#include <cstdlib>


int main() {
	
	NodeBST<int> n(10);
	NodeBST<int> n1(107);
	NodeBST<int> n2(120);

	cout << n1 << endl;
	cout << n2 << endl;
	cout << n << endl;
	
	BST<int> tree;
	BST<int> tree_deg;
	srand(0);

	for(int i=0; i < 20; i++) {
		tree.insert(rand() % 201);
		tree_deg.insert(i);
	}

	tree.inorder();
	tree_deg.inorder();
}
