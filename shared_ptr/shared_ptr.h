#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#define HZ_CHECK_MEMORY_LEAKS

#ifdef HZ_CHECK_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // HZ_CHECK_MEMORY_LEAKS

#include <algorithm>
#include <assert.h>
#define HZ_ASSERT(x) assert(x)

template <typename T>
class shared_ptr {
public:
	void swap(shared_ptr& lhs) noexcept {
		std::swap(ptr_, lhs.ptr_);
		std::swap(ref_, lhs.ref_);
	}

	// 注意异常安全代码
	explicit shared_ptr(T* p) { // may throw std::bad_alloc
		ref_ = new long(1);
		ptr_ = p;
	}

	// copy constructor
	shared_ptr(shared_ptr& lhs) noexcept { // no allocation allowed in this path
		ptr_ = lhs.ptr_;
		ref_ = lhs.ref_;
		(*ref_)++;
	}

	// move copy constructor
	shared_ptr(shared_ptr&& lhs) noexcept {
		swap(lhs);
	}

	~shared_ptr() noexcept {
		HZ_ASSERT((*ref_) > 0);
		(*ref_)--;
		if((*ref_) == 0) {
			delete ptr_;
			ptr_ = nullptr;

			delete ref_;
			ref_ = nullptr;
		}

		// must set nullptr
		ptr_ = nullptr;
		ref_ = nullptr;
	}

	// using the copy-and-swap idiom (copy constructor and swap method)
	// 注意这里传入的是值类型,因为在c++里有move constructor可以来优化,所以性能不差.此外这样写就保证了copy-and-swap
	shared_ptr& operator=(shared_ptr ptr) noexcept {
        swap(ptr);
        return *this;
    }

	operator bool() const noexcept {
        return (0 < (*ref_));
    }
    bool unique(void) const noexcept {
        return 1 == *ref_;
    }
    long use_count(void)  const noexcept {
        return *ref_;
    }

    // underlying pointer operations :
    T& operator*() const noexcept {
        HZ_ASSERT(nullptr != ptr_);
        return *ptr_;
    }
    T* operator->() const noexcept {
        HZ_ASSERT(nullptr != ptr_);
        return ptr_;
    }
    T* get(void)  const noexcept {
        return ptr_;
    }

private:
	T*					ptr_ = nullptr;
	long*				ref_ = nullptr;
};

template <typename T, typename ...Args>
shared_ptr<T> make_shared(Args&&... args) {
	// should user placement new, 一次性分配ref_及ptr_的空间
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif // SHARED_PTR_H