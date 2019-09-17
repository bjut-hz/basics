#ifndef SLICE_H_
#define SLICE_H_

#include<vector>
#include<assert.h>
#include "basic.h"

#define USE_SMART_POINTER
#ifndef USE_SMART_POINTER
#include<stdlib.h>
template<typename T>
class slice {
	class Array {
	public:
		int refs_;	// used for memory management

		int len_;
		T* ptr_;	// 

		explicit Array(int len) {
			len_ = len;
			ptr_ = new T[len_];
			refs_ = 0;

			if (std::is_pod<T>::value) {
				memset(ptr_, 0, len_ * sizeof(T));
			}
		}

		~Array() {
			assert(0 == refs_);
			delete[]ptr_;
		}

		int Ref() {
			return ++refs_;
		}

		void UnRef() {
			--refs_;
			assert(refs_ >= 0);
			if (refs_ <= 0) {
				delete this;
			}
		}
	};

public:
	slice() : slice(0, 1) {}
	explicit slice(int len) : slice(len, len) {}

	slice(int len, int cap) {
		assert(len <= cap);

		len_ = len;
		cap_ = cap == 0 ? 1 : cap;

		arr_ = new Array(cap_);
		arr_->Ref();
		ptr_ = arr_->ptr_;
	}

	slice(slice& s, int start, int end) : slice(&s, start, end) {
		//len_ = end - start;
		//cap_ = len_;

		//arr_ = s.arr_;
		//arr_->Ref();

		//ptr_ = arr_->ptr_ + start;
	}

	slice(slice* s, int start, int end) {
		len_ = end - start;
		cap_ = len_;

		arr_ = s->arr_;
		arr_->Ref();

		ptr_ = arr_->ptr_ + start;
	}

	slice(std::vector<T>& vec) : slice(vec, 0, vec.size()) {}

	slice(std::vector<T>& vec, int start, int end) : slice(end - start, end - start) {
		for (int i = start; i < end; ++i) {
			ptr_[i] = vec[i];
		}
	}

	// copy constructor
	slice(const slice& lhs) {
		Copy(lhs);
	}

	// move constructor
	slice(slice && lhs) {

		arr_ = lhs.arr_;
		len_ = lhs.len_;
		cap_ = lhs.cap_;
		ptr_ = lhs.ptr_;

		lhs.arr_ = nullptr;
		lhs.ptr_ = nullptr;
	}

	slice& operator= (const slice& lhs) {
		if (this == &lhs) {
			return *this;
		}

		Copy(lhs);
		return *this;
	}



	~slice() {
		//assert(nullptr != arr_);
		if (nullptr != arr_) {
			arr_->UnRef();
		}

		ptr_ = nullptr;
		arr_ = nullptr;
	}

	T& operator[] (int index) {
		assert(index < len_);

		return ptr_[index];
	}

	inline int len() { return len_; }
	inline int cap() { return cap_; }

	void Append() {}
	template<typename Type, typename ...Args>
	void Append(Type&& ele, Args&&... args) {
		using type = typename std::enable_if<std::is_convertible<Type, T>::value, void>::type;
		if (len_ >= cap_) {
			// expand the memory
			if (cap_ <= 1024) {
				cap_ = cap_ << 1;
			}
			else {
				cap_ = cap_ + cap_ >> 1;
			}


			auto arr = new Array(cap_);
			arr->Ref();

			// copy to new allocated memory
			if (std::is_pod<T>::value) {
				memmove(arr->ptr_, ptr_, sizeof(T) * len_);
			}
			else {
				for (int i = 0; i < len_; ++i) {
					arr->ptr_[i] = ptr_[i];
				}
			}
			ptr_ = arr->ptr_;

			arr_->UnRef();
			arr_ = arr;
		}
		ptr_[len_++] = std::forward<Type>(ele);

		//std::cout << sizeof(T) << sizeof(*ptr_) << std::endl;
		Append(std::forward<Args>(args)...);
	}

	void Append(slice& s) {
		for (int i = 0; i < s.len(); ++i) {
			Append(s[i]);
		}
	}

private:
	void Copy(const slice& lhs) {
		// UnRef the old array
		if (nullptr != arr_) {
			arr_->UnRef();
		}

		arr_ = lhs.arr_;
		len_ = lhs.len_;
		cap_ = lhs.cap_;
		ptr_ = lhs.ptr_;

		// add reference count
		lhs.arr_->Ref();
	}


private:
	int 				len_ = 0;
	int 				cap_ = 0;
	T* 					ptr_ = nullptr;

public:
	Array*				arr_ = nullptr;
};

#else
#include<memory>

template<typename T>
class slice {
public:
	explicit slice(int len) : slice(len, len) {}

	slice(int len, int cap) : len_(len), cap_(cap) {
		s_ptr_ = std::make_shared<std::vector<T>>(cap);
		iter_ = s_ptr_->begin();
	}

	slice(slice& s, int start, int end) : slice(&s, start, end) {}

	slice(slice* s, int start, int end) {
		len_ = end - start;
		cap_ = len_;

		s_ptr_ = s->s_ptr_;

		iter_ = s->s_ptr_->begin() + start;
	}

	slice(std::vector<T>& vec) : slice(vec, 0, vec.size()) {}

	slice(std::vector<T>& vec, int start, int end) : slice(end - start, end - start) {
		for (int i = start; i < end; ++i) {
			this->operator[](i) = vec[i];
		}
	}

	// copy constructor
	slice(const slice& lhs) = default;
	~slice() = default;


public:
	T& operator[] (int index) {
		assert(index < len_);
		return *(iter_ + index);
	}

public:
	inline int len() { return len_; }
	inline int cap() { return cap_; }


	void Append() {}
	template<typename Type, typename ...Args>
	void Append(Type&& ele, Args&&... args) {
		if (len_ >= cap_) {
			// expand the memory
			if (cap_ <= 1024) {
				cap_ = cap_ << 1;
			}
			else {
				cap_ = cap_ + cap_ >> 1;
			}

			// should hold the raw content and do not let dctor to release it
			auto tmp = s_ptr_;
			s_ptr_ = std::make_shared<std::vector<T>>(cap_);
			std::copy(iter_, iter_ + len_, s_ptr_->begin());

			iter_ = s_ptr_->begin();
		}
		this->operator[](len_++) = std::forward<Type>(ele);

		Append(std::forward<Args>(args)...);
	}

	void Append(slice& s) {
		for (int i = 0; i < s.len(); ++i) {
			Append(s[i]);
		}
	}

private:
	int					len_ = 0;
	int					cap_ = 0;
	
	using Iterator = typename std::vector<T>::iterator;
	Iterator			iter_;

public:
	std::shared_ptr<std::vector<T>> s_ptr_;
};

#endif // !USE_SMART_POINTER


#endif // SLICE_H_