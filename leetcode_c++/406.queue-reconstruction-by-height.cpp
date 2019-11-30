/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (61.73%)
 * Likes:    1935
 * Dislikes: 224
 * Total Accepted:    97.1K
 * Total Submissions: 157.2K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * Example
 * 
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> res;
        for(auto& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};
// @lc code=end

