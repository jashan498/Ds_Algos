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

// function to insert nodes at ith position with arguments:(head, i, data) [ITERATIVE]

// Node * insert(Node * head, int i, int data){

// 	Node * temp = head;
// 	int count = 0;

// 	if(i == 0){
// 		Node * newNode = new Node(data);
// 		newNode -> next = head;
// 		head = newNode;
// 		return head;
// 	}

// 	while(count < i){
// 		temp = temp -> next;
// 	}

// 	Node * newNode = new Node(data);
// 	newNode -> next = temp -> next;
// 	temp -> next = newNode;

// 	return head;
// }



// function to insert nodes at ith position with arguments:(head, i, data) [RECURSIVE]

Node* insertNodeRec(Node *head, int i, int data) {
		if(head == NULL){
			if(i == 0){
				Node *newNode=new Node(data);
				return newNode;
			}
			else
				return head;
		}

		Node *newNode=new Node(data);

		if(i == 0)    //base condition
		{
			newNode -> next = head;
			head = newNode;
			return head;
		}

		head -> next = insertNodeRec(head -> next, i-1, data);
		return head;
	}

// Finding length of linked list [RECURSIVE]

int length(Node *head) {
    if(head == NULL){
    	return 0;
    	}

    return 1 + length(head -> next);   
	}



// Deleting a node [RECURSIVELY]. Arg: (head, i)

Node* deleteNodeRec(Node *head, int i) {
  	
  	if(i>length(head)-1)     // If index given is gretaer than LL length then return same head
      return head;
  
	if(i == 0){                      // Base condition
		Node * temp = head;
		head = head -> next;
		delete temp;
		return head;
	}

	head->next = deleteNodeRec(head -> next, i - 1);
	return head;   
    
}


int main(){

	Node * head = createLL();
	// cout<<"yolo";
	// head = insert(head, 2, 100);
	head = insertNodeRec(head, 2, 100);
	int len = length(head);
	cout<<len<<endl;
	print(head);

	return 0;

}