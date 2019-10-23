/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    // // brute force, time limit exceeded
    // int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    //     int cnt = 0;
    //     for(auto& a : A) {
    //         for(auto& b : B) {
    //             for(auto& c : C) {
    //                 for(auto& d : D) {
    //                     if(a + b + c + d == 0) ++cnt;
    //                 }
    //             }
    //         }
    //     }
    //     return cnt;
    // }
    
    // hash map
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> dict;
        for(auto& c : C) {
            for(auto& d : D) {
                ++dict[c+d];
            }
        }

        int cnt = 0;
        for(auto& a : A) {
            for(auto& b : B) {
                if(dict.find(0 - a - b) != dict.end()) {
                    cnt += dict[0 - a - b];
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

