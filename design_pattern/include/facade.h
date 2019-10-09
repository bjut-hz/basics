#ifndef FACADE_H_
#define FACADE_H_

#include<iostream>
#include "basic.h"

namespace DP {
	class SubSystemOne {
	public:
		void MethodOne() {
			std::cout << "SubSystemOne::MethodOne" << std::endl;
		}
	};

	class SubSystemTwo {
	public:
		void MethodTwo() {
			std::cout << "SubSystemTwo::MethodTwo" << std::endl;
		}
	};

	// 对外提供一个整合了原本旧的子系统功能的统一接口,使得客户端更容易使用原功能
	class Facade {
	public:
		void MethodA() {
			sub_sys_one_.MethodOne();
		}
	
		void MethodB() {
			std::cout << "Facade::MethodB" << std::endl;
			sub_sys_two_.MethodTwo();
			sub_sys_one_.MethodOne();
		}
	private:
		SubSystemOne sub_sys_one_;
		SubSystemTwo sub_sys_two_;
	};
} // namespace DP

#endif // FACADE_H_