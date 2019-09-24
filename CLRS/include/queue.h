#ifndef QUEUE_H_
#define QUEUE_H_

#include<vector>
#include<assert.h>
#include "basic.h"

namespace CLRS {
	namespace {
		const static int N = 3;
	}
	class LimitedQueue {
	public:
		void Enqueue(int num) {
			assert(length_ < N);

			++length_;
			tail_ = Succ(tail_);
			elements_[tail_] = num;
		}

		int Dequeue() {
			assert(length_ > 0);

			int first = elements_[head_];
			--length_;
			head_ = Succ(head_);
			return first;
		}

	private:
		inline int Succ(int value) {
			if(++value == N) {
				value = 0;
			}
			return value;
		}
	private:
		int head_ = 1;
		int tail_ = 0;
		int length_ = 0;
		int elements_[N];
	};

	class Queue {
	public:
		void Enqueue(int num) {
			elements_.push_back(num);
		}
		int Dequeue() {
			int first = elements_.front();
			elements_.erase(elements_.begin());
			return first;
		}
	private:
		std::vector<int> elements_;
	};
} // namespace CLRS

#endif // QUEUE_H_