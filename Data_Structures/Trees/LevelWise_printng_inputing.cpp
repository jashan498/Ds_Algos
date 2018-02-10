#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> * takeInputLevelWise(){
	int rootData;
	cout<<"Enter root data "<<endl;
	cin>>rootData;

	TreeNode<int>* root = new TreeNode<int>(rootData);

	//queue for pending nodes to be joined
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){

		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout<<"Enter number of children of "<<front<<endl;
		int numChild;
		cin>>numChild;

		for(int i=0;i<numChild;i++){

			int childData;
			cout<<"Enter "<<i+1<<"th child of "<<front->data<<endl;
			cin>>childData;

			// Creating and pushing of child inside queue
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}

	return roots;
}