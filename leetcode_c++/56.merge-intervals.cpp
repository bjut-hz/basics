/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        for(auto& interval : intervals) {
            if(ans.empty()) {
                ans.push_back(interval);
            } else {
                vector<int>& tmp = ans.back();

                if(interval[0] > tmp[1]) {
                    ans.push_back(interval);
                } else {
                    tmp[1] = max(tmp[1], interval[1]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

