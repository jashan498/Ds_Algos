#include <iostream>
#include "TreeNode.h"
using namespace std;

// Function to find number of nodes
int numOfNodes(TreeNode<int>* root) {
    
  	int ans=1;
  
  	for(int i=0;i<root->children.size();i++)
    {
      ans += numOfNodes(root->children[i]);
    }
  	
  	return ans;
}

// Function to find sum of all nodes
int sumOfNodes(TreeNode<int>* root) {

  	int ans=root->data;
  
  	for(int i=0;i<root->children.size();i++)
    {
      ans += sumOfNodes(root->children[i]);
    }
  	
  	return ans;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){

	if(root == NULL)   //edge case
	{
		return root;
	}
	TreeNode<int> *max = root;
	for(int i=0;i<root->children.size();i++){
		TreeNode<int> *temp = maxDataNode(root->children[i]);
		if(temp->data > max->data){
			max=temp;
		}
	}

	return max;
}