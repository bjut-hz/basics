/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (49.68%)
 * Likes:    913
 * Dislikes: 315
 * Total Accepted:    261.6K
 * Total Submissions: 526.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());

    //     vector<int> res;
    //     int i = 0;
    //     int j = 0;
    //     while(i < nums1.size() && j < nums2.size()) {
    //         if(nums1[i] < nums2[j]) {
    //             ++i;
    //         } else if(nums1[i] > nums2[j]) {
    //             ++j;
    //         } else {
    //             res.push_back(nums1[i]);
    //             i++;
    //             j++;
    //         }
    //     }
    //     return res;
    // }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        map<int, int> m;
        for(auto& num : nums1) {
            m[num]++;
        }

        vector<int> res;
        for(auto& num : nums2) {
            if(m[num] > 0) {
                res.push_back(num);
                m[num]--;
            }
        }

        return res;
    }
};
// @lc code=end

