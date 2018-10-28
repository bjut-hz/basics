package implementTrie

/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true

Note:
	You may assume that all inputs are consist of lowercase letters a-z.
	All inputs are guaranteed to be non-empty strings.
*/

type node struct {
	ch uint8
	isWord bool
	child map[uint8]*node
}

type Trie struct {
	root *node
}


/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{root:&node{isWord:false, ch:'0', child:make(map[uint8]*node, 26)}}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
	N := len(word)
	pos := this.root
	for i := 0; i < N; i++ {
		if _, ok := pos.child[word[i] - 'a']; !ok {
			newNode := &node{ch:word[i], isWord:false, child:make(map[uint8]*node, 26)}
			pos.child[word[i] - 'a'] = newNode
		}
		if i == (N - 1) {
			pos.child[word[i] - 'a'].isWord = true
		}

		pos = pos.child[word[i] - 'a']
	}
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	N := len(word)
	pos := this.root
	for i := 0; i < N; i++ {
		if _, ok := pos.child[word[i] - 'a']; !ok {
			return false
		} else {
			if i == (N - 1) && pos.child[word[i] - 'a'].isWord {
				return true
			}
			pos = pos.child[word[i] - 'a']
		}
	}
	return false
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	N := len(prefix)
	pos := this.root
	for i := 0; i < N; i++{
		if _, ok := pos.child[prefix[i] - 'a']; !ok {
			return false
		}
		pos = pos.child[prefix[i] - 'a']
	}
	return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */