// Program to find mid-point of a given linked list

// We will have two pointers, both at head initially.
// One of thwm will traverse one node at a time while other
// would have twice the speed. So when the faster pointer
//complete its traversal, the slower one would be at
//mid-point 

#include<iostream>
#include "node.cpp"
using namespace std;

// FINDING MID-POINT

Node * midpoint_linkedlist(Node * head)
{

	if(head == NULL || head -> next == NULL){
		return head;
	}

	Node * slow = head, *fast = head -> next;

	while(fast != NULL && fast->next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;
	}

	return slow
}

