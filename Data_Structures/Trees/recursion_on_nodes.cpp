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

// Function to find address of node with largest data
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

//////////////////// HEIGHT OF A GENERIC TREE /////////////////////////

int height(TreeNode<int>* root){
	int ans=0;

	for(int i=0;i<root -> children.size();i++)
	{
		int childHeight = height(root->children[i]);

		if(childHeight > ans){
			ans = childHeight;
		}
	}
	return ans + 1;
}

/////////////////  PRINT ALL NODES AT DEPTH ``k``  //////////////////////

void printAtLevelK(TreeNode<int>* root, int k){
	if(root == NULL)        // Edge case
		return;

	if(k == 0){			    // Base case
		cout<< root->data<<endl;
		return;
	}

	for(int i=0;i<root -> children.size(); i++){
		printAtLevelK(root->children[i], k-1)
	}
}

/////////////////  NUMBER OF LEAF NODES   /////////////////////////


int numLeafNodes(TreeNode<int>* root) {
	int count = 0;	
  	if(root -> children.size() == 0)
      count++;

  	for(int i=0;i<root->children.size();i++) {
      count += numLeafNodes(root -> children[i]);
    }
  
  	return nleaf;
}
