#ifndef __BASIC_H__
#define __BASIC_H__

#define HZ_CHECK_MEMORY_LEAKS

#ifdef HZ_CHECK_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DBG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif // HZ_CHECK_MEMORY_LEAKS


#endif // !__BASIC_H__

// 在程序退出的时候，调用_CrtDumpMemoryLeaks函数
