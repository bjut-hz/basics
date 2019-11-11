/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //     set<int> s(nums.begin(), nums.end());

    //     int len = 0;

    //     for(auto& num : nums) {
    //         if(!s.count(num)) continue;

    //         s.erase(num);
    //         int pre = num - 1;
    //         int next = num + 1;

    //         while(s.count(pre)) {
    //             s.erase(pre--);
    //         }

    //         while(s.count(next)) {
    //             s.erase(next++);
    //         }

    //         len = max(len, next - pre - 1);
    //     }

    //     return len;
    // }

    int longestConsecutive(vector<int>& nums) {
        map<int, int> m; // 表示该数字对应的最大连续值
        int res = 0;
        for(auto& num : nums) {
            if(m.count(num)) continue; // 如果已经存在，不需求解
            int left = m.count(num-1) ? m[num-1] : 0;
            int right = m.count(num + 1) ? m[num + 1] : 0;

            int sum = left + right + 1;
            res = max(res, sum);
            m[num] = sum;

            // 注意更新连续数字的最左侧以及最右侧对应的，该数字可能把左右连接了起来
            m[num - left] = sum; 
            m[num + right] = sum;
        }

        return res;
    }
};
// @lc code=end

