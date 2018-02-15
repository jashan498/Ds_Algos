#include <iostream>
using namespace std;

template <template T>
class BinaryTreeNode{

	T data;
	BinaryTreeNode * left;
	BinaryTreeNode * right;

	BinaryTreeNode(T data){
		this -> data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {      // Destructor because you should clean your mess
		delete left;
		delete right;
	}
};