#ifndef STACK_H_
#define STACK_H_

#include<vector>
#include<assert.h>
#include "basic.h"
namespace CLRS {
	class Stack {
	public:
		bool empty() {
			return 0 == elements_.size();
		}

		void Push(int num) {
			elements_.push_back(num);
		}

		int Pop() {
			assert(!empty());
			int top = elements_.back();
			elements_.pop_back();
			return top;
		}
	private:
		std::vector<int> elements_;
	};
} // namespace CLRS
#endif