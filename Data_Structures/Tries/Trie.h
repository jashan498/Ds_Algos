#include "TreiNode.h"

class Trie {

	TreiNode * root;

public:

	Trie(){
		root = new TreiNode("\0");
	}

	// Helper function
	void insertWord(TreiNode* root, string word){

		// Base case
		if(word.size() == 0){
			root -> isTerminal = true;
			return;
		}

		// Some calculations before recursive step
		int index = word[0] - "a";

		if(root -> children != NULL){
			child = root -> children[index];
		}

		else{
			child = new TreiNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive step
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word){
		insertWord(root, word);
	}

	void removeWord(TreiNode* root, string word){
		//TODO
	}
};
