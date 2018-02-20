#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

////////////// Print Tree(recursively) //////////////////

void printTree(BinaryTreeNode<int>* root) {
	if(root == NULL) {      // Base case
		reutrn;
	}
	cout<< root -> data << " : ";
	if(root -> left != NULL) {
		cout << "L" << root -> left -> data;
	}

	if(root -> right != NULL) {
		cout << "L" << root -> right -> data;
	}

	printTree(root -> left);
	printTree(root -> right);
}


////////////// Take Input(recursively) ///////////////////

// Input the data of a node, if ``-1`` is encountered,
// it would indicate no further child of that node

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;

	if (rootData == -1) {       // That is there is no further child of node
		return NULL;
	}

	// As previous `if` confirms there is a child, let's start our real bussiness
	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> * leftChild = takeInput();
	BinaryTreeNode<int> * rightChild = takeInput();

	root -> left = leftChild;
	root -> right = rightChild;

	return root;
}
