#include <climits>

class StackUsingArray{

	int * data;
	int nextIndex;
	int capacity;

public:

	StackUsingArray(int totalSize){
		data = new int[totalSize];
		nextIndex = 0;
		capacity = totalSize;
	}

	//return number of elements in stack
	int size(){
		return nextIndex;
	}

	bool isEmpty(){
		return nextIndex == 0;
	}

	//insert element
	void push(int element){

	if(nextIndex == capacity){
		cout<<"Stack Full"<<endl;
		return;
	}

	data[nextIndex] = element;
	nextIndex++;
	}

	//delete element
	int pop(){
		if(isEmpty()){
			cout<<"Stack Empty !"<<endl;
			return INT_MIN;
		}
	nextIndex--;
	return data[nextIndex];
	}

	// Show element
	int top(){
		if(isEmpty()){
			cout<<"Stack Empty !"<<endl;
			return INT_MIN;
		}

	return data[nextIndex - 1];
	}
};