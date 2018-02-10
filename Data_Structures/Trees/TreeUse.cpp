#include <iostream>
#include "TreeNode.h"
using namespace std;

// Function to print a tree. Output for:
//               1
//              / \
//             2   3
//            /\ 
//           4  5
// 1 : 2, 3, 
// 2 : 4, 5, 
// 4 : 
// 5 : 
// 3 :
void printTree(TreeNode<int> * root){

	if(root == NULL){
		return;
	}

	cout << root -> data << " : ";
	for(int i=0; i<root->children.size(); i++){
		cout<<root->children[i]->data<<", ";
	}

	cout<<endl;
	for(int i=0; i<root->children.size(); i++){
		printTree(root->children[i]);
	}
}

// Function for making a tree
TreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter  Data"<<endl;
	cin>>rootData;

	TreeNode<int> * root =new TreeNode<int>(rootData);
	int n;
	cout<<"Enter Number of children of "<<rootData<<endl;
	cin>>n;

	for(int i=0;i<n;i++){
		TreeNode<int> * child = takeInput();
		root->children.push_back(child);
	}

	return root;
}

int main(){

	// Example for making tree manually
	// TreeNode<int> * root = new TreeNode<int>(1);
	// TreeNode<int> * node1 = new TreeNode<int>(2);
	// TreeNode<int> * node2 = new TreeNode<int>(3);

	// root -> children.push_back(node1);
	// root -> children.push_back(node2);
	
	TreeNode<int> * root = takeInput();
	printTree(root);
	return 0;
}  