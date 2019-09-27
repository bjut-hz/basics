#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include<string>
#include<assert.h>
#include "basic.h"

namespace CLRS {
	class BST {
	public:
		struct Node {
			int val;
			Node* left = nullptr;
			Node* right = nullptr;
			Node* p = nullptr; 				// parent
		};

		using BstTree = Node*;

	public:
		~BST() {
			while(root_ != nullptr) {
				Delete(root_);
			}
		}

		std::string InorderTraverse() {
			return InorderTraverse(root_);
		}


		Node* Search(int val) {
			return Search(val, root_);
		}

		Node* root() { return root_; }

		Node* min() {
			return Minimum(root_);
		}

		Node* max() {
			return Maximum(root_);
		}

		Node* Successor(Node* x) {
			if(nullptr == x) return x;

			if(nullptr != x->right) return Minimum(x->right);

			auto y = x->p;
			while(y != nullptr && y->right == x) {
				x = y;
				y = y->p;
			}
			return y;
		}

		void Insert(int val) {
			Node* z = new Node();
			z->val = val;

			Node** x = &root_;
			Node* y = nullptr;
			while(*x != nullptr) {
				y = *x;
				if(val < (*x)->val) { 
					x = &(*x)->left;
				} else {
					x = &(*x)->right;
				}
			}

			z->p = y;
			*x = z; // can use for both empty and non-empty tree
		}

		void Delete(Node* z) {
			if(nullptr == z) return;

			if(z->left == nullptr) {
				Transplant(z, z->right);
			} else if(z->right == nullptr) {
				Transplant(z, z->left);
			} else {
				Node* y = Minimum(z->right);
				if(y->p != z) {
					Transplant(y, y->right);
					y->right = z->right;
					y->right->p = y;
				}

				Transplant(z, y);
				y->left = z->left;
				y->left->p = y;
			}
			delete z;
		}

	private:
		// replace u with v
		void Transplant(Node* u, Node* v) {
			if(u->p == nullptr) {
				root_ = v;
			} else if(u == u->p->left) {
				u->p->left = v;
			} else {
				u->p->right = v;
			}

			if(v != nullptr) {
				v->p = u->p;
			}
		}

		Node* Search(int val, Node* x) {
			if(x == nullptr || x->val == val) {
				return x;
			}
			if(val < x->val) {
				return Search(val, x->left);
			} else {
				return Search(val, x->right);
			}
		}

		Node* Minimum(Node* x) {
			while(x != nullptr && x->left != nullptr) {
				x = x->left;
			}
			return x;
		}

		Node* Maximum(Node* x) {
			while(x != nullptr && x->right != nullptr) {
				x = x->right;
			}
			return x;
		}

		std::string InorderTraverse(Node* x) {
			std::string str = "";
			if(x != nullptr) {
				str += InorderTraverse(x->left);
				str += " " + std::to_string(x->val);
				str += InorderTraverse(x->right);
			}
			return str;
		}

	private:
		Node* root_ = nullptr;
	};
}

// data structure and algrithm analysis version
namespace DS_C {
	class BST {
	public:
		struct Node {
			int val;
			Node* left = nullptr;
			Node* right = nullptr;
		};

	using SearchTree = Node*;
	using Position = Node*;

	public:
		~BST() {
			while (root_ != nullptr) {
				root_ = Delete(root_, root_->val);
			}
		}
		std::string InorderTraverse() {
			return InorderTraverse(root_);
		}

		Position Find(int val) {
			auto x = root_;
			while(x != nullptr && x->val != val) {
				if(val < x->val) {
					x = x->left;
				} else {
					x = x->right;
				}
			}
			return x;
		}
		Position FindMin() {
			return FindMin(root_);
		}
		Position FindMax() {
			auto x = root_;
			while(x != nullptr && x->right != nullptr) {
				x = x->right;
			}
			return x;
		}

		void Insert(int val) {
			root_ = Insert(root_, val);
		}

		void Delete(int val) {
			root_ = Delete(root_, val);
		}

	private:
		SearchTree Insert(SearchTree t, int val) {
			if(nullptr == t) {
				t = new Node();
				t->val = val;
				return t;
			}

			if(val < t->val) {
				t->left = Insert(t->left, val);
			} else if(val > t->val) {
				t->right = Insert(t->right, val);
			}

			return t;
		}

		Position FindMin(SearchTree t) {
			auto x = t;
			while(x != nullptr && x->left != nullptr) {
				x = x->left;
			}
			return x;
		}

		SearchTree Delete(SearchTree t, int val) {
			assert(t);

			if(val < t->val) {
				t->left = Delete(t->left, val);
			} else if(val > t->val) {
				t->right = Delete(t->right, val);
			} else { // find the val's position
				if(t->left && t->right) { // two children
					Position tmp = FindMin(t->right);
					t->val = tmp->val;
					t->right = Delete(t->right, tmp->val);
				} else { // one or zero children
					Position tmp = t;
					if(t->left == nullptr) {
						t = t->right;
					} else if(t->right == nullptr) {
						t = t->left;
					}

					delete tmp;
				}
			}
			return t;
		}

		std::string InorderTraverse(Node* x) {
			std::string str = "";
			if(x != nullptr) {
				str += InorderTraverse(x->left);
				str += " " + std::to_string(x->val);
				str += InorderTraverse(x->right);
			}
			return str;
		}
	private:
		Node* root_ = nullptr;
	};
}

#endif // BINARY_SEARCH_TREE_H_