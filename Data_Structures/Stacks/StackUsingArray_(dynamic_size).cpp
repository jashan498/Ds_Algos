#include <climits>

class StackUsingArray{

	int * data;
	int nextIndex;
	int capacity;

public:

	StackUsingArray(){
		data = new int[4];   // any random size
		nextIndex = 0;
		capacity = 4;
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

	if(nextIndex == capacity){                            // If current size of array is not sufficient
		int * newData = new int[2*capacity];			  // Make a new array inside heap with 
														  // double the capacity
		for(int i=0; i<capacity; i++){
			newData[i] = data[i];						  // copy data to new array
		}

		capacity *= 2;                                    // update capacity
		delete [] data;									  // deallocate the older memory
		data = newData;
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