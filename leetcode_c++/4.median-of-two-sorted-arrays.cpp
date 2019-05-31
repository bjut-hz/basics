/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
	int min2(int a, int b) {
		return a > b ? b : a;
	}
	// find Kth min number
	int findKth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int K) {
		// 注意这里,永远让nums1是长度较小的数组，否则还得判断
        if ((r1 - l1) > (r2 - l2)) return findKth(nums2, l2, r2, nums1, l1, r1, K);

		if (r1 == l1) {return nums2[K - 1];}

		if (K == 0 || K == 1) { return min2(nums1[l1], nums2[l2]); }

		// 注意这里怎么凑够了K个数
		int p = min2(K / 2, r1 - l1);
		int q = K - p;
        // 由于c++里没有slice,必须注意数组的开始下标!!!!
		if (nums1[l1 + p-1] == nums2[l2 + q-1]) {
			return nums1[l1 + p-1];
		} else if (nums1[l1 + p-1] > nums2[l2 + q-1]) {
			return findKth(nums1, l1, r1, nums2, l2 + q, r2, K - q);
		} else {
			return findKth(nums1, l1 + p, r1, nums2, l2, r2, K - p);
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = nums1.size() + nums2.size();
		if (len & 0x1) {
			return findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len / 2 + 1);
		} else {
			auto r1 = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len / 2);
			auto r2 = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len / 2 + 1);
			return double(r1 + r2) / 2;
		}
	}
};



