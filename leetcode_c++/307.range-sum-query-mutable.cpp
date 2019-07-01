/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// // brute force
// class NumArray {
// public:
// 	NumArray(vector<int>& nums) {
// 		nums_ = nums;
// 	}

// 	void update(int i, int val) {
// 		nums_[i] = val;
// 	}

// 	int sumRange(int i, int j) {
// 		int sum = 0;
// 		for (; i <= j; ++i) {
// 			sum += nums_[i];
// 		}
// 		return sum;
// 	}
	
// private:
// 	vector<int> nums_;
// };


// 数组分段
// 思路：把整个大数组分成段,对段内的数据进行更改，防止了遍历整个数组
// class NumArray {
// public:
// 	NumArray(vector<int>& nums) {
// 		if (nums.empty()) return;

// 		nums_ = nums;

// 		// 此处不能直接转为int,否则下一步里两个运算树都是int,结果为int,而不是得到浮点后向上取整
// 		double N = sqrt(nums.size());
// 		len_ = ceil((nums.size()) / N);
// 		// build sum block
// 		block_.resize(len_);
// 		for (int i = 0; i < nums.size(); ++i) {
// 			block_[i / len_] += nums[i];
// 		}
// 	}

// 	void update(int i, int val) {
// 		block_[i / len_] += (val - nums_[i]);
// 		nums_[i] = val;
// 	}

// 	int sumRange(int i, int j) {
// 		int start = i / len_;
// 		int end = j / len_;
		
// 		int result = 0;

// 		if (start == end) {
// 			for (int k = i; k <= j; ++k) {
// 				result += nums_[k];
// 			}
// 			return result;
// 		}

// 		for (int k = i; k < (start + 1) * len_; ++k) {
// 			result += nums_[k];
// 		}

// 		for (int k = start + 1; k < end; ++k) {
// 			result += block_[k];
// 		}

// 		for (int k = end * len_; k <= j; ++k) {
// 			result += nums_[k];
// 		}

// 		return result;
// 	}
	
// private:
// 	vector<int> nums_, block_;
// 	int len_;
// };


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

