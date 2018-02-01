//program of making Linked List only with a node class

#include<iostream>
#include "node.cpp"
using namespace std;

// function to print Linked List

void print(Node* head){

	Node * temp = head;

	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}

	return;
}

// function to create a linked list until ``-1`` is not encountered as input

Node* createLL(){

	int data;
	cin >> data;
	Node * head = NULL;

	while(data != -1){
		Node * newNode = new Node(data);

		if(head == NULL){
			head = newNode;
		}

		else{
			Node * temp = head;
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = newNode;
		}

		cin >> data;
	}

	return head;
}

int main(){

	Node * head = createLL();
	print(head);

	return 0;

}