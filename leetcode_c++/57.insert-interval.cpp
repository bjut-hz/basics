/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     vector<vector<int>> ans;

    //     int i = 0;
    //     for(i = 0; i < intervals.size(); ++i) {
    //         if(intervals[i][1] < newInterval[0]) {
    //             ans.push_back(intervals[i]);
    //         } else {
    //             break;
    //         }
    //     }
    //     // 这个循环以前已经排除了所有在新区间之前的区间，如果左区间不大于新区间的右区间，肯定是相交的
    //     while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
    //         newInterval[0] = min(newInterval[0], intervals[i][0]);
    //         newInterval[1] = max(newInterval[1], intervals[i][1]);
    //         ++i;
    //     }

    //     ans.push_back(newInterval);

    //     for(; i < intervals.size(); ++i) {
    //         ans.push_back(intervals[i]);
    //     }
    //     return ans;
    // }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int cur = 0;
        for(auto& ele : intervals) {
            if(ele[1] < newInterval[0]) {
                ++cur;
                ans.push_back(ele);
            } else if(ele[0] > newInterval[1]) {
                ans.push_back(ele);
            } else {
                // merge
                newInterval[0] = min(ele[0], newInterval[0]);
                newInterval[1] = max(ele[1], newInterval[1]);
            }
        }

        ans.insert(ans.begin() + cur, newInterval);
        return ans;
    }
};
// @lc code=end

