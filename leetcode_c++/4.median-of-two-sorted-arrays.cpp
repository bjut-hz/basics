/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size() + nums2.size();
        if(N & 0x1) {
            return findKth(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, N / 2 + 1);
        } else {
            double ret = 0;
            double m1 = findKth(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, N / 2);
            double m2 = findKth(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, N / 2 + 1);
            return (m1 + m2) / 2;
        }
    }

    int findKth(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int K) {
        if((r1 - l1) > (r2 - l2)) return findKth(nums2, nums1, l2, r2, l1, r1, K);

        if(l1 > r1) { 
            return nums2[K - 1];
        }

        if(K == 0 || K == 1) {
            return min(nums1[l1], nums2[l2]);
        }

        int p = min(K / 2, (r1 - l1 + 1));
        int q = K - p;

        if(nums1[l1 + p - 1] == nums2[l2 + q - 1]) {
            return nums1[l1 + p - 1];
        } else if(nums1[l1 + p - 1] > nums2[l2 + q - 1]) {
            return findKth(nums1, nums2, l1, r1, l2 + q, r2, K - q);
        } else {
            return findKth(nums1, nums2, l1 + p, r1, l2, r2, K - p);
        }
    }
};
// @lc code=end

