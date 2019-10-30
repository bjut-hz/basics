/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
class WordDictionary {
private:
	struct Node {
	public:
		Node* children[26];
		bool is_word;
	public:
		explicit Node() {
			for (int i = 0; i < 26; ++i) {
				children[i] = nullptr;
			}
			is_word = false;
		}
	};
public:
	/** Initialize your data structure here. */
	WordDictionary() {}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node* pos = &root;
		for (int i = 0; i < word.size(); ++i) {
			auto tmp = pos->children[word[i] - 'a'];
			if (tmp == nullptr) {
				pos->children[word[i] - 'a'] = new Node();
			}
			pos = pos->children[word[i] - 'a'];
		}
        pos->is_word = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return helper(&root, word, 0);
	}

	bool helper(Node* node, string& word, int pos) {
		if (node == nullptr) {
			return false;
		}

		if (pos == word.size()) {
			return node->is_word;
		} 

		if (word[pos] == '.') {
			for (int i = 0; i < 26; ++i) {
                if(helper(node->children[i], word, pos + 1)) {
                    return true;
                }
			}
		} else {
			return helper(node->children[word[pos] - 'a'], word, pos + 1);
		}
        return false;
	}
public:
	Node root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

