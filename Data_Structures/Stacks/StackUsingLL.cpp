#include<iostream>
using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node<T> * next;

	Node(T data){
		this -> data = data;
		this -> next = NULL;
	}
};

template <typename T>
class stack{
	Node<T> * head;
	int size;

public:

	stack(){
		head = NULL;
		size = 0;
	}

	T getSize(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}

	void push(T data){
		Node<T> * newNode = new Node<T>(data);
		newNode -> next = head;
		head = newNode;
		size++;
	}

	T pop(){
		if(isEmpty())
			return 0;

		T ans = head -> data;
		Node<T> * temp = head;
		head = head -> next;
		delete temp;
		size--;
		return ans;
	}

	T top(){
		if(isEmpty())
			return 0;
		return head -> data;
	}
};
