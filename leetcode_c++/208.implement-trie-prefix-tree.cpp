/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
private:
	struct Node {
		Node* children[26];
		char ch;
		bool is_word;
		Node() {
			memset(children, 0, sizeof(Node*) * 26);
			is_word = false;
		}
	};

private:
	Node head_;
public:
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node* ptr = &head_;
		for (int i = 0; i < word.size(); ++i) {
			char ch = word[i];
			if (NULL == (ptr->children[ch - 'a'])) {
				Node* n = new Node();
				n->ch = ch;

				ptr->children[ch - 'a'] = n;
			}
			ptr = ptr->children[ch - 'a'];
			if (i == word.size() - 1) {
				ptr->is_word = true;
			}
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node* ptr = &head_;
		for (int i = 0; i < word.size(); ++i) {
			char ch = word[i];
			if (NULL == ptr->children[ch - 'a']) return false;
			ptr = ptr->children[ch - 'a'];
			if (i == word.size() - 1) {
				return ptr->is_word;
			}
		}

		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node* ptr = &head_;
		for (int i = 0; i < prefix.size(); ++i) {
			char ch = prefix[i];
			if (NULL == ptr->children[ch - 'a']) return false;
			ptr = ptr->children[ch - 'a'];
		}
		return true;
	}
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

