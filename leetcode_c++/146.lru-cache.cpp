/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
private:
	struct Node {
		Node*       pre;
		Node*       next;
		int			key;
		int         val;
	};
private:
	map<int, Node*>         map_;
	Node                    dummy_;
	int                     capacity_;

private:
	void InsertAfter(Node* at, Node* node) {
		node->next = at->next;
		node->pre = at;
		at->next->pre = node;
		at->next = node;
	}

	void Remove(Node* at) {
		at->pre->next = at->next;
		at->next->pre = at->pre;

        at->pre = NULL;
        at->next = NULL;
	}
public:
	LRUCache(int capacity) {
		capacity_ = capacity;
		dummy_.next = &dummy_;
		dummy_.pre = &dummy_;
	}

	int get(int key) {
		if (!map_.count(key)) return -1;

		Node* ptr = map_[key];
		Remove(ptr);
		InsertAfter(&dummy_, ptr);
		return ptr->val;
	}

	void put(int key, int value) {
		if (map_.count(key)) {
			// update
			Node* ptr = map_[key];
			ptr->val = value;
			Remove(ptr);
			InsertAfter(&dummy_, ptr);
		} else {
			// insert a new one
			if (map_.size() >= capacity_) {
				Node* ptr = dummy_.pre;
				map_.erase(ptr->key);
				Remove(ptr);
				delete(ptr);
			}

			Node* node = new Node();
			node->key = key;
			node->val = value;
			map_[key] = node;
			InsertAfter(&dummy_, node);
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

