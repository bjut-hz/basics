#ifndef RED_BLACK_H_
#define RED_BLACK_H_

#include<string>
#include<assert.h>
#include "basic.h"

namespace CLRS {
	enum ColorType {
		kRed,
		kBlack,
	};
	using ElementType = int;
	
	struct RedBlackNode {
		ElementType key;
		ColorType color = kRed;
		RedBlackNode* left = nullptr;
		RedBlackNode* right = nullptr;
		RedBlackNode* p = nullptr;
	};

	struct RedBlackTree {
		RedBlackNode* root;
		RedBlackNode* nil;
	};

	RedBlackTree New() {
		RedBlackTree rb;
		rb.nil = new RedBlackNode();
		rb.nil->color = kBlack;
		rb.root = rb.nil;
		return rb;
	}

	void Destroy(RedBlackTree& T) {
		auto Destroy_ = Y(
			[&](auto&& self, RedBlackNode* x) -> void {
				if (x != T.nil) {
					self(x->left);
					self(x->right);
					delete x;
				}	
			}
		);

		Destroy_(T.root);
		delete T.nil;
	}

	std::string InorderTraverse(RedBlackTree& T) {
		auto Traverse = Y([&](auto&& self, RedBlackNode* x) ->std::string {
			std::string str{ "" };
			if (x != T.nil) {
				str += self(x->left);
				str += std::to_string(x->key) + " ";
				str += self(x->right);
			}
			return str;
		});

		return Traverse(T.root);
	}

	void LeftRotate(RedBlackTree& T, RedBlackNode* x) {
		assert(x->right != T.nil);
		auto y = x->right;
		x->right = y->left;

		if(y->left != T.nil) {
			y->left->p = x;
		}

		y->p = x->p;
		if(x->p == T.nil) {
			T.root = y;
		} else if(x == x->p->left) {
			x->p->left = y;
		} else {
			x->p->right = y;
		}

		y->left = x;
		x->p = y;
	}

	void RightRotate(RedBlackTree& T, RedBlackNode* y) {
		assert(y->left != T.nil);
		auto x = y->left;
		y->left = x->right;
		if(x->right != T.nil) {
			x->right->p = y;
		}

		x->p = y->p;
		
		if(y->p == T.nil) {
			T.root = y;
		} else if(y == y->p->left) {
			y->p->left = x;
		} else {
			y->p->right = x;
		}
		x->right = y;
		y->p = x;
	}

	RedBlackNode* Minimum(RedBlackTree& T, RedBlackNode* x) {
		while(x != T.nil && x->left != T.nil) {
			x = x->left;
		}
		return x;
	}

	void Insert(RedBlackTree& T, RedBlackNode* z) {
		auto InsertFixup = [](RedBlackTree& T, RedBlackNode* z) {
			while(z->p->color == kRed) {
				if(z->p == z->p->p->left) {
					auto y = z->p->p->right;

					if(y->color == kRed) {
						z->p->color = kBlack;
						y->color = kBlack;
						z->p->p->color = kRed;
						z = z->p->p;
					}
					else {
						if (z == z->p->right) {
							z = z->p;
							LeftRotate(T, z);
						}

						z->p->color = kBlack;
						z->p->p->color = kRed;
						RightRotate(T, z->p->p);
					}

				} else {
					auto y = z->p->p->left;

					if(y->color == kRed) {
						z->p->color = kBlack;
						y->color = kBlack;
						z->p->p->color = kRed;
						z = z->p->p;
					}
					else {
						if (z == z->p->left) {
							z = z->p;
							RightRotate(T, z);
						}

						z->p->color = kBlack;
						z->p->p->color = kRed;
						LeftRotate(T, z->p->p);
					}

				}
			}
			T.root->color = kBlack;
		};

		auto y = T.nil;
		auto x = T.root;

		while(x != T.nil) {
			y = x;
			if(z->key < x->key) {
				x = x->left;
			} else {
				x = x->right;
			}
		}
		z->p = y;
		if(y == T.nil) {
			T.root = z; // first element
		} else if(z->key < y->key) {
			y->left = z;
		} else {
			y->right = z;
		}

		z->left = T.nil;
		z->right = T.nil;
		z->color = kRed;

		InsertFixup(T, z);
	}

	void Transplant(RedBlackTree& T, RedBlackNode* u, RedBlackNode* v) {
		if(u->p == T.nil) {
			T.root = v;
		} else if(u == u->p->left) {
			u->p->left = v;
		} else {
			u->p->right = v;
		}
		v->p = u->p;
	}

	void Delete(RedBlackTree& T, RedBlackNode* z) {
		auto DeleteFixup = [](RedBlackTree &T, RedBlackNode* x) {
			while(x != T.root && x->color == kBlack) {
				if(x == x->p->left) {
					auto w = x->p->right;
					if(w->color == kRed) {
						w->color = kBlack;
						x->p->color = kRed;
						LeftRotate(T, x->p);
						w = x->p->right;
					}

					if(w->left->color == kBlack && w->right->color == kBlack) {
						w->color = kRed;
						x = x->p;
					} else {
						if(w->right->color == kBlack) {
							w->left->color = kBlack;
							w->color = kRed;
							RightRotate(T, w);
							w = x->p->right;
						}
						w->color = x->p->color;
						x->p->color = kBlack;
						w->right->color = kBlack;
						LeftRotate(T, x->p);
						x = T.root;
					}

				} else {
					if(x == x->p->right) {
						auto w = x->p->left;
						if(w->color == kRed) {
							w->color = kBlack;
							x->p->color = kRed;
							RightRotate(T, x->p);
							w = x->p->left;
						}

						if(w->right->color == kBlack && w->left->color == kBlack) {
							w->color = kRed;
							x = x->p;
						} else {
							if(w->left->color == kBlack) {
								w->right->color = kBlack;
								w->color = kRed;
								LeftRotate(T, w);
								w = x->p->left;
							}
							w->color = x->p->color;
							x->p->color = kBlack;
							w->left->color = kBlack;
							RightRotate(T, x->p);
							x = T.root;
						}
					}
				}
			}
			x->color = kBlack;
		};

		auto y = z;
		auto y_old_color = y->color;
		RedBlackNode* x = nullptr;
		if(z->left == T.nil) {
			x = z->right;
			Transplant(T, z, z->right);
		} else if(z->right == T.nil) {
			x = z->left;
			Transplant(T, z, z->left);
		} else {
			y = Minimum(T, z->right);
			y_old_color = y->color;

			x = y->right;
			if(y->p == z) {
				x->p = y;
			} else {
				Transplant(T, y, y->right);
				y->right = z->right;
				y->right->p = y;
			}

			Transplant(T, z, y);
			y->left = z->left;
			y->left->p = y;
			y->color = z->color;
		}

		delete z;

		if(y_old_color == kBlack) {
			DeleteFixup(T, x);
		}
	}
	
} // namespace CLRS

#endif // RED_BLACK_H_