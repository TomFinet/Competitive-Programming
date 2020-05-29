/**
    trie.cpp
    Purpose: provides functionality for the trie data-structure.

    @author Tom Finet
    @version 1.0 21/05/20
*/

#include <"trie.hpp">


struct TrieNode* makeNode() {
	// makes a new node
}


bool insert(struct TrieNode *root, string word) {
	// check root is not null
	if(root == nullptr) {
		root = new TrieNode;
	}


	struct TrieNode *currNode = root;
	for(char &c : word) {
		struct TrieNode nextNode = currNode->children[c - 'a'];

		if(nextNode == NULL) {
			// create new node
			nextNode = new TrieNode;
		}

		nextNode.isEnd = false;
		currNode = *nextNode;
	}

	currNode->isEnd = true;

	return true;
}


bool search(struct TrieNode *root, string word) {
	if(root == nullptr) {
		return false;
	}

	struct TrieNode *currNode = root;
	for(char &c : word) {
		struct TrieNode nextNode = currNode->children[c - 'a'];

		if(nextNode.isEnd)
	}
}


