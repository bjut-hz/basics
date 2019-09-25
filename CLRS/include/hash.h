#ifndef HASH_H_
#define HASH_H_

#include<assert.h>
#include<memory>
#include "basic.h"

namespace CLRS {
	int Hash(int key) {
		return key;
	}


	struct Handle {
		int key;		// only support int value, can use void* to support any type
		int hash;		// hash value for this handle
		int value;

		Handle* next;
	};

	class HandleTable {
	public:
		HandleTable() : length_(0), elems_(0), list_(nullptr) { Resize(); }
		~HandleTable() {
			for(int i = 0; i < length_; ++i) {
				while(list_[i] != nullptr) {
					Remove(&list_[i]);
				}
			}
			delete []list_;
		}

		Handle* Lookup(int key, int hash) {
			return *FindPointer(key, hash);
		}

		void Remove(int key, int hash) {
			Remove(FindPointer(key, hash));
		}

		Handle* Insert(int key, int hash, int value) {
			Handle** ptr = FindPointer(key, hash);
			Handle* h = *ptr;
			
			if(h == nullptr) { // insert a new key
				h = new Handle();
				h->key = key;
				h->hash = hash;
				h->value = value;
				h->next = nullptr;
				*ptr = h;

				++elems_;
				if(elems_ > length_) {
					Resize();
				}
			} else {
				h->value = value;
			}
			return h;
		}

	private:
		void Remove(Handle** ptr) {
			Handle* tmp = *ptr;
			if(tmp != nullptr) {
				*ptr= tmp->next;
				--elems_;
			}
			delete tmp;
		}

		Handle** FindPointer(int key, int hash) {
			Handle** ptr = &list_[Hash(hash, length_)];
			while(*ptr != nullptr && ((*ptr)->hash != hash || key != (*ptr)->key)) {
				ptr = &(*ptr)->next;
			}
			return ptr;
		}
		// we should make sure that load factor is smaller than 1
		void Resize() {
			int new_length = 4;
			while(new_length < elems_) {
				new_length <<= 1;
			}

			Handle** new_list = new Handle*[new_length];
			memset(new_list, 0, sizeof(new_list[0]) * new_length);
			
			int count = 0;
			for(int i = 0; i < length_; ++i) {
				Handle* h = list_[i];
				while(h != nullptr) {
					Handle* next = h->next;
					int hash = h->hash;

					Handle** ptr = &list_[Hash(hash, new_length)];
					h->next = *ptr;
					*ptr = h;
					h = next;
					++count;
				}
			}

			assert(elems_ == count);
			delete []list_;
			list_ = new_list;
			length_ = new_length;
		}

		inline int Hash(int hash, int length) {
			return hash & (length - 1);
		}
	private:
		int length_;
		int elems_;					// element count
		Handle** list_;
	};
} // namespace CLRS

#endif // HASH_H_