#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_
#include<vector>
#include<assert.h>
class MaxHeap {
public:
	explicit MaxHeap(std::vector<int>& nums) : nums_(nums.size() + 1), heap_size_(nums.size()) {
		std::copy(nums.begin(), nums.end(), nums_.begin() + 1);
		BuildMaxHeap();
	}

	MaxHeap() : nums_(1), heap_size_(0) {}

	inline int size(){ return heap_size_;}
	inline int max() {return nums_[1];}
	int ExtractMax() {
		assert(size() >= 1);

		auto ret = max();
		nums_[1] = nums_[heap_size_];
		heap_size_ -= 1;

		if(2 * heap_size_ < nums_.size()) {
			nums_.resize( nums_.size() / 2);
		}

		MaxHeapify(1);
		return ret;
	}

	void Insert(int value) {
		heap_size_ += 1;
		if(heap_size_ >= nums_.size()) {
			nums_.resize(heap_size_ * 2);
		}
		nums_[heap_size_] = INT_MIN;
		HeapIncreaseKey(heap_size_, value);
	}

private:
	inline int Parent(int i) {return i / 2;} 
	inline int Left(int i) {return i * 2;}
	inline int Right(int i) {return i * 2 + 1;}

	// both left and right child is MaxHeap
	void MaxHeapify(int i) {
		auto l = Left(i);
		auto r = Right(i);
		int largest = i;
		if(l <= size() && nums_[l] > nums_[largest]) {
			largest = l;
		}
		if(r <= size() && nums_[r] > nums_[largest]) {
			largest = r;
		}

		if(largest != i) {
			std::swap(nums_[i], nums_[largest]);
			MaxHeapify(largest);
		}
	}

	void BuildMaxHeap() {
		for(int i = size() / 2; i >= 1; --i) {
			MaxHeapify(i);
		}
	}

	void HeapIncreaseKey(int i, int key) {
		assert(key > nums_[i]);

		nums_[i] = key;
		while(i > 1 && nums_[Parent(i)] < nums_[i]) {
			std::swap(nums_[i], nums_[Parent(i)]);
			i = Parent(i);
		}
	}
private:
	std::vector<int> nums_; // can put sentinel at 0 index
	int heap_size_;
};
#endif // MAX_HEAP_H_