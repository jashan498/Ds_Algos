#include <iostream>
#include "TreeNode.h"
using namespace std;

/////////////  PRE ORDER TRAVERSAL  //////////////////

void preorder(TreeNode<int>* root) {

	if (root == NULL)    // See i am a responsible coder
		return;

	cout<<root -> data<< " ";

	for(int i=0;i< root-> children.size(); i++)
	{
		preorder(root -> children[i]);
	}
}
