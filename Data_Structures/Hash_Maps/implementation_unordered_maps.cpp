# include<iostream>
# include<string>

using namespace std;

template<typename V>
class MapNode{
public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key, V value) {
		this -> key = key;
		this -> value = value;
		next = NULL;
	}

	~MapNode(){
		delete next;
	}
};

template<typename V>
class ourmap{
	MapNode<V>** buckets;
	int count;  //Total number of values in whole map
	int numBuckets;

public:
	ourmap(){
		size = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];

		for(int i =0;i< numBuckets; i++){
			buckets[i] = NULL;
		}
	}

	~ourmap(){
		for(int i =0;i< numBuckets; i++){
			delete buckets[i];
		}

		delete[] buckets
	}

private:
	int getBucketIndex(string key){
		int hashcode = 0;
		int currentCoeff = 1;

		for(int i =key.length()-1; i>=0; i--){

			hashcode += key[i]*currentCoeff;           // Write string in form of
			hashcode = hashcode % numBuckets;         // 'abc' = a*p^2 + b*p^1 + c*p^0

			currentCoeff *= 37;                       // p = 37
			currentCoeff = currentCoeff % numBuckets;    // as (n1*n2) % r = ((n1 % r) * (n2 % r)) % r
		}

		return hashcode % numBuckets;
	}

public:

	void rehash() { 					// rehashes the old map to newer one to reduce n/b ratio.
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>*[2*numBuckets];

		for(int i =0; i< 2*numBuckets; i++)
		{
			buckets[i] = NULL;
		}

		int oldBucketCount = numBuckets;
		numBuckets *= 2;  // double the size of array
		count = 0;

		for(int i =0; i < oldBucketCount; i++)
		{
			MapNode<V>* head = temp[i];  // To traverse older map

			while(head != NULL){
				string key = head -> key;
				V value = head -> value;
				insert(key, value);
				head = head -> next;
			}
		}

		for(int i = 0; i < oldBucketCount; i++)
		{
			MapNode<V>* head = temp[i];
			delete head;
		}

		delete [] temp;

	}



	void size(){
		return count;
	}

	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key);

		MapNode<V>* head = buckets[bucketIndex];

		while(head != NULL){
			if(head -> key == key){  // if Key exists, just update its value
				head -> value = key;
				return;
			}
			head = head -> next;
		}

		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);

		node -> next = head;
		buckets[bucketIndex] = node;
		count++;

		int loadfactor = size()/numBuckets;
		if(loadfactor > 0.7){
			rehash();
		}
	}

	void remove(string key) {
		int bucketIndex = getBucketIndex(key);

		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;

		while(head != NULL){
			if(head -> key == key){  // if Key exists, just update its value
				if(prev == NULL){
					buckets[bucketIndex] = head -> next;
				}
				else{
					prev->next = head->next;
				}

				V value = head -> value;

				head->next=NULL;
				delete head;
				count--;
				return value;
			}

			prev = head;
			head = head->next;

		}

		return 0;
	}

	V getValue(string key){
		// Similar to ourmap.remove()
	}

};