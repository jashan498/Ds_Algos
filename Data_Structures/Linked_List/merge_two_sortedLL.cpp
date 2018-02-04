// Function to Merge two SORTED linked list
// We will take two var nhead and ntail, pointing to
// head and tail of new head and tail respectively.
// Nntail would be compared every time with Min(head1,head2)
// and that value be next ntail (along with ``Min(head1,head2) = Min(head1,head2) -> next``)

#include<iostream>
#include "Node.cpp"
using namespace std;

Node* mergeTwoLLs(Node *head1, Node *head2) {

    Node *nhead, *ntail;

    if(head2 -> data >=  head1 -> data){        //nhead = ntail = Min(head1, head2)
    		nhead = head1;
    		ntail = head1;
    		head1 = head1 -> next;
    }

    else{
    		nhead = head2;
    		ntail = head2;
    		head2 = head2 -> next;
    }

    while(head1 != NULL && head2  != NULL){
   
    		if(head2 -> data >=  head1 -> data){       // Min(head1, head2) would be next node in our MERGED LL
    		ntail -> next = head1;
            ntail = ntail -> next;
    		head1 = head1 -> next;
    	}

    else{
    		ntail -> next = head2;
      		ntail = ntail -> next;
    		head2 = head2 -> next;
    	}

    }
  
  	if(head1 != NULL)           //if head2 was exhausted before
      ntail -> next = head1;
  
  	if(head2 != NULL)           //if head1 was exhausted before
      ntail -> next = head2;

   

    return nhead;

    
}