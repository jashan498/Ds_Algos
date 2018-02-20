#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

////////////// Take_Input(Level Wise) ///////////////////

BinaryTreeNode<int>* takeInputlevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;

	if (rootData == -1) {        // That an empty tree with no node
		return NULL;
	}

	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() 1= 0) {
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter left child of " << front -> data <<endl;
		int leftchildData;
		cin >> leftchildData;

		if (leftchildData != -1) {      		// Inputing ``-1`` means there is no left child 
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchildData);
			front -> left = child;
			pendingNodes.push(child);
		}

		// Doing same for right child
		cout << "Enter right child of " << front -> data <<endl;
		int rightchildData;
		cin >> rightchildData;

		if (rightchildData != -1) {      		// Inputing ``-1`` means there is no left child 
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchildData);
			front -> right = child;
			pendingNodes.push(child);
		}
	}

	return root;
}