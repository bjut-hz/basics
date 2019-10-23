/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        const int N = bits.size();
        for(; i < N - 1;) {
            if(bits[i] == 1) {
                i += 2;
            } else {
                i += 1;
            }
        }

        return i == N - 1;
    }
};
// @lc code=end

