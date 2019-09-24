#ifndef LIST_H_
#define LIST_H_
#include<iterator>
#include "basic.h"

namespace CLRS {
	class List;
	class ListNode {
	public:
		ListNode() = default;
		explicit ListNode(int val) : val_(val) {}
		ListNode* next_ = nullptr;
		int val_ = 0;
	};

	class ListIterator {
		public:
			// Iterator traits, previously from std::iterator.
			using value_type = int;
			using difference_type = std::ptrdiff_t;
			using poTer = int*;
			using reference = int&;
			using iterator_category = std::forward_iterator_tag;

			ListIterator() = default;
			ListIterator(List* l);

			// Dereferencable.
			reference operator*() const {
				return ptr_->val_;
			}

			// Pre- and post-incrementable.
			ListIterator& operator++() {
				ptr_ = ptr_->next_;
				return *this;
			}

			ListIterator operator++(int){
				ListIterator tmp = *this;
				ptr_ = ptr_->next_;
				return tmp;
			}

			// Equality / inequality.
			bool operator==(const ListIterator& rhs) {
				if(rhs.ptr_ == ptr_) return true;
				if(rhs.ptr_ == nullptr || ptr_ == nullptr) return false;

				return ptr_->val_ == rhs.ptr_->val_;
			}
			bool operator!=(const ListIterator& rhs) {
				return !(*this == rhs);
			}


		private:
			ListNode* ptr_ = nullptr;
	};
	
	// use pointer to pointer to Insert and Remove a element
	class List{
	public:
		List() = default;
		~List() {
			ListNode* ptr = head_.next_;
			while (ptr != nullptr) {
				ListNode* tmp = ptr;
				ptr = ptr->next_;
				delete tmp;
			}
		}


		void Insert(int val) {
			// insert at front
			ListNode* node = new ListNode(val);
			ListNode** ptr = &head_.next_;

			node->next_ = *ptr;
			*ptr = node;
		}

		int Remove(int val) {
			ListNode** ptr = FindPointer(val);
			ListNode* result = *ptr;
			if(result != nullptr) {
				*ptr = result->next_;
			}
			int tmp = result->val_;
			delete result;
			return tmp;
		}

		bool Find(int val) {
			auto ptr = FindPointer(val);
			return *ptr != nullptr;
		}

		ListIterator begin() const {
			ListIterator l(const_cast<List*>(this));
			return l;
		}
		ListIterator end() const {
			ListIterator l(nullptr);
			return l;
		}

		friend class ListIterator;

	private:
		ListNode** FindPointer(int val) {
			ListNode** ptr = &head_.next_;
			while(*ptr != nullptr && (*ptr)->val_ != val) {
				ptr = &(*ptr)->next_;
			}
			return ptr;
		}

	private:
		ListNode head_; // dummy node
	};

	// must put here to get a completed ListIterator type
	ListIterator::ListIterator(List* l) {
		if (l != nullptr) {
			ptr_ = l->head_.next_;
		}
	}


	class DoubleLinkedList {
	public:
		class Node {
		public:
			Node() = default;
			explicit Node(int val) : val_(val){}

			Node* prev_ = nullptr;
			Node* next_ = nullptr;
			int val_ = 0;
		};

	public:
		DoubleLinkedList() {
			dummy_.next_ = &dummy_;
			dummy_.prev_ = &dummy_;
		}

		~DoubleLinkedList() {
			while(dummy_.next_ != &dummy_) {
				Remove(dummy_.next_);
			}
		}

		Node* Find(int val) {
			Node* pos = dummy_.next_;
			while(pos != &dummy_) {
				if(pos->val_ == val) {
					return pos;
				}
				pos = pos->next_;
			}
			return nullptr;
		}

		Node* Insert(int val) {
			Node* new_node = new Node(val);
			Insert(&dummy_, new_node);
			return new_node;
		}
		void Remove(Node* pos) {
			pos->prev_->next_ = pos->next_;
			pos->next_->prev_ = pos->prev_;
			
			delete pos;
			pos = nullptr;
		}

	private: 
		void Insert(Node* pos, Node* new_node) {
			new_node->next_ = pos->next_;
			pos->next_ = new_node;

			new_node->next_->prev_ = new_node;
			new_node->prev_ = pos;
		}

	private:
		Node dummy_;
	};
} // namespace CLRS

#endif // LIST_H_