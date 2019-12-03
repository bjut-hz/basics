/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (47.04%)
 * Likes:    2161
 * Dislikes: 424
 * Total Accepted:    118.9K
 * Total Submissions: 252.8K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 统计出现最多的字母的个数,放的方法就是先放置这些字母,n个空闲位中放置其它字符
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnts(26, 0);
        for(auto& ch : tasks) {
            cnts[ch - 'A']++;
        }
        sort(cnts.begin(), cnts.end());

        int mx_cnt = cnts[25];
        int i = 25;
        while(i >= 0 && cnts[i] == mx_cnt) --i;
        return max(int(tasks.size()), (mx_cnt - 1) * (n + 1) + (25 - i));
    }
};
// @lc code=end

