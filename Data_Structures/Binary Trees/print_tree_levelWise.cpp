#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

///////////////////// Print Tree Level Wise ////////////////////////////

void printLevelWise(BinaryTreeNode<int> *root) {

	if(root == NULL)
		return;

	queue<BinaryTreeNode<int> *> q;
	q.push(root);

	while(!q.empty())
	{
		BinaryTreeNode<int>* node = q.front();
		q.pop();

		if(node==NULL)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}

		else
		{
			cout<<node->data<<":";

			cout<<"L:";
			if(node->left)
			{
				q.push(node->left);
				cout<<node->left->data<<", ";
			}
			else
			{
				cout<<-1<<",";
			}


			cout<<"R:";
			if(node->left)
			{
				q.push(node->right);
				cout<<node->right->data<<", ";
			}
			else
			{
				cout<<-1<<",";
			}
		}
	}
}