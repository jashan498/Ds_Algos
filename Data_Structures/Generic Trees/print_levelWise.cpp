#include <iostream>
#include "TreeNode.h"
using namespace std;

// This methods prints the tree level wise
// for tree:              1
//                       / \  
//                      2   3
//                     / \
//                    4   5
// output:
// 1:2,3
// 2:4,5
// 3:
// 4:
// 5:

// Similar to taking input level wise:
// That is, insert first push the root into a queue
// now when it is pop out, insert into the queue its children
// and print the roots data
// Similar process followed with the nodes in queue

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
  
    while(pendingNodes.size()!=NULL){
      TreeNode<int>* front = pendingNodes.front();
      pendingNodes.pop();
      
      for(int i=0;i<front->children.size();i++){
        pendingNodes.push(front->children[i]);
      }
      
      cout<<front->data<<":";
      for(int i=0;i<front->children.size();i++){
        if(i<front->children.size() - 1){
          cout<<front->children[i]->data<<",";
        }
        
        else{
        cout<<front->children[i]->data;}
      }
      
      cout<<endl;
      
    }
  
    return;
}