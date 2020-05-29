/**
    trie.hpp
    Purpose: declares the trie data structure.

    @author Tom Finet
    @version 1.0 21/05/20
*/

#ifndef TRIE
#define TRIE

#include <string>

const int CHAR_SET = 26;

/**
 * Stores a rooted tree where each node points to 26 possible nodes
 */
struct TrieNode {
	struct TrieNode *children[CHAR_SET];
	bool isEnd;
}

/**
 * Inserts a word into the trie.
 *
 * @param root the root of the trie.
 * @param word the word we are adding to the trie.
 *
 * @return true if the insertion was successful, false otherwise.
 * 	
 */
bool insert(struct TrieNode *root, string word);

/**
 * Searches for a word in the trie.
 *
 * @param root the root of the trie.
 * @param word the word we are searching for in the trie.
 *
 * @return true if the word was found, false otherwise.
 * 	
 */
bool search(struct TrieNode *root, string word);

#endif