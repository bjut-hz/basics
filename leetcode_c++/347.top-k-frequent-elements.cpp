/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (57.59%)
 * Likes:    2061
 * Dislikes: 136
 * Total Accepted:    274.1K
 * Total Submissions: 476K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto& num : nums) {
            m[num]++;
        }

        // pair比较大小的时候先比较first元素再比较second
        priority_queue<pair<int,int>> heap;
        for(auto& ele : m) {
            heap.push({ele.second, ele.first});
        }

        vector<int> res;
        for(int i = 0; i < k; ++i) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
// @lc code=end

