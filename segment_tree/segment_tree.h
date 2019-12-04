#ifndef SEGMENT_TREE_H

#include<vector>

class SegmentTree {
public:
	// 叶子节点保存数组数据
	struct Node {
		int 		start = 0;					// [start, end]
		int			end = 0;
		int 		sum = 0;					// can be max/min
		Node*		left = nullptr;
		Node*		right = nullptr;
	};

public:
	// O(N)
	SegmentTree(std::vector<int>& vals) {
		if(vals.empty()) return;
		root_ = BuildTree(vals, 0, vals.size() - 1);
	}

	~SegmentTree() {
		Destroy(root_);
	}

	// O(lgN)
	void Update(int index, int val) {
		UpdateTree(root_, index, val);
	}
	// O(lgN + K)
	int RangeQuery(int start, int end) {
		return QuerySum(root_, start, end);
	}

private:
	void Destroy(Node* root) {
		if(root) {
			Destroy(root->left);
			Destroy(root->right);
		}
		delete root;
		root = nullptr;
	}

	Node* BuildTree(std::vector<int>& vals, int start, int end) {
		Node* root = new Node();
		root->start = start;
		root->end = end;
		
		if(start == end) {
			root->sum = vals[start];
			return root;
		}

		int mid = start + (end - start) / 2;
		root->left = BuildTree(vals, start, mid);
		root->right = BuildTree(vals, mid + 1, end);
		root->sum = root->left->sum + root->right->sum;
		return root;
	}

	void UpdateTree(Node* root, int index, int val) {
		if(root->start == root->end && root->start == index) {
			root->sum = val;
			return;
		}

		int mid = root->start + (root->end - root->start) / 2;
		if(index <= mid) {
			UpdateTree(root->left, index, val);
		} else {
			UpdateTree(root->right, index, val);
		}

		root->sum = root->left->sum + root->right->sum;
	}

	int QuerySum(Node* root, int i, int j) {
		if(root->start == i && root->end == j) {
			return root->sum;
		}

		int mid = root->start + (root->end - root->start) / 2;
		if(j <= mid) {
			return QuerySum(root->left, i, j);
		} else if(i > mid) {
			return QuerySum(root->right, i, j);
		} else {
			return QuerySum(root->left, i, mid) + QuerySum(root->right, mid + 1, j);
		}
	}
private:
	Node*	root_ = nullptr;
};


#endif // SEGMENT_TREE_H