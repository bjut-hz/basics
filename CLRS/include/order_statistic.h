#ifndef ORDER_STATISTIC_H_
#define ORDER_STATISTIC_H_

#include<vector>
#include<algorithm>
#include<assert.h>
namespace CLRS {
	// O(N)
	int Minimum(std::vector<int>& nums) {
		const int N = nums.size();
		assert(N >= 1);

		int ret = nums[0];
		for(int i = 1; i < N; ++i) {
			if(nums[i] < ret) {
				ret = nums[i];
			}
		}
		return ret;
	}

	// O(N)
	int Maximum(std::vector<int>& nums) {
		const int N = nums.size();
		assert(N >= 1);

		int ret = nums[0];
		for(int i = 1; i < N; ++i) {
			if(nums[i] > ret) {
				ret = nums[i];
			}
		}
		return ret;
	}

	// 3(N/2)
	void MaxAndMin(std::vector<int>& nums, int& max, int& min) {
		const int N = nums.size();
		assert(N >= 1);

		max = nums[0];
		min = nums[0];
		int i = 0;
		for(i = 1; i + 1 < N; i = i + 2) {
			if(nums[i] > nums[i+1]) {
				if(nums[i] > max) {
					max = nums[i];
				}

				if(nums[i+1] < min) {
					min = nums[i+1];
				}
			} else {
				if(nums[i+1] > max) {
					max = nums[i+1];
				}

				if(nums[i] < min) {
					min = nums[i];
				}
			}
		}

		if (i < N) {
			if (nums[i] > max) {
				max = nums[i];
			}

			if (nums[i] < min) {
				min = nums[i];
			}
		}
	}


	// find Kth num
	int RandomizedSelect(std::vector<int>& nums, int l, int r, int K) {
		assert(K <= r - l + 1);

		if(l == r) return nums[l];

		auto Partition = [](std::vector<int>& nums, int l, int r) -> int {
			auto x = nums[r];
			auto i = l - 1;

			for(int j = l; j <= r - 1; ++j) {
				if(nums[j] <= x) { 
					// find the num smaller than x and put it in the right position
					// p <= k <= i, nums[k] <=x
					i = i + 1;
					std::swap(nums[i], nums[j]);
				}
			}
			std::swap(nums[i+1], nums[r]);
			return i + 1; // the position of pivot
		};

		auto RandomizedPartition = [&](std::vector<int>& nums, int l, int r) {
			auto i = std::rand() % (r - l + 1) + l;
			std::swap(nums[r], nums[i]);

			return Partition(nums, l, r);
		};

		int p = RandomizedPartition(nums, l, r);
		int left_num = p - l + 1;
		if(left_num == K) return nums[p];
		if(left_num < K) {
			return RandomizedSelect(nums, p + 1, r, K - left_num);
		} else {
			return RandomizedSelect(nums, l, p - 1, K);
		}
	}

	int Select(std::vector<int>& nums, int l, int r, int K) {
		assert(K <= r - l + 1);
	
		if(l == r) return nums[l];
	
		const int kNum = 5;
		const int N = r - l + 1;
		const int num_group = N / kNum;
		std::vector<std::vector<int>> vecs(num_group);
		std::vector<int> median;
		int pos = 0;
		for(int i = 0; i < num_group; ++i) {
			vecs[i].resize(kNum);
			std::copy(nums.begin() + l + pos, nums.begin() + l + pos + kNum, vecs[i].begin());
			pos += kNum;

			std::stable_sort(vecs[i].begin(), vecs[i].end());
			median.push_back(vecs[i][kNum/2]);
		}

		if(pos != N) {
			vecs.push_back(std::vector<int>(N - pos));
			std::copy(nums.begin() + l + pos, nums.begin() + r + 1, vecs.back().begin());
			std::stable_sort(vecs.back().begin(), vecs.back().end());
			median.push_back(vecs.back()[vecs.back().size()/2]);
		}
		int x = Select(median, 0, median.size() - 1, median.size() / 2);
		auto Partition = [](std::vector<int>& nums, int l, int r, int pivot) ->int {
			auto i = l - 1;
			for(int j = l; j <= r; ++j) {
				if(nums[j] < pivot) {
					i = i + 1;
					std::swap(nums[i], nums[j]);
				}
			}
			return i + 1 - l; // the amount of number smaller than pivot
		};

		int c = Partition(nums, l, r, x);
		if(c + 1 == K) return x;
		if(c + 1 < K) {
			return Select(nums, l + c, r, K - c);
		} else {
			return Select(nums, l, l + c - 1, K);
		}
	}
} // namespace CLRS

#endif // ORDER_STATISTIC_H_