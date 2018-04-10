#include <iostream>
#include <vector>

using namespace std;

class priority_queue {
	vector<int> pg;

public:

	bool isEmpty() {
		return pq.size() == 0;
	}

	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()){
			return 0;
		}

		return pq[0];
	}

	void insert(int element) {

		pq.push_back(element);

		int childIndex  pq.size() - 1;

		while(childIndex > 0) {

			int parentIndex = (childIndex - 1)/2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pa[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}

			else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMin() {
		// To Do
	}

};