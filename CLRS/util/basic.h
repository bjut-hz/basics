#ifndef BASIC_H_
#define BASIC_H_

#define HZ_CHECK_MEMORY_LEAKS

#ifdef HZ_CHECK_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // HZ_CHECK_MEMORY_LEAKS

#include<type_traits>
// Y combinator
template<typename Functor>
struct YBuiler {
	Functor functor;
	template<typename... Args>
	decltype(auto) operator()(Args&&... args) const& {
		return functor(*this, std::forward<Args>(args)...);
	}
};

template<typename Functor>
YBuiler<typename std::decay<Functor>::type> Y(Functor&& functor)
{
    return{ std::forward<Functor>(functor) };
}

#endif // BASIC_H_

// 在程序退出的时候，调用_CrtDumpMemoryLeaks函数
