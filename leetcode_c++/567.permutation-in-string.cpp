/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(128, 0);
        vector<int> v2(128, 0);


        // for(int i = 0; i < s1.size(); ++i) {
        //     ++v1[s1[i]];
        // }

        // for(int i = 0, j = 0; j < s2.size(); ++j) {
        //     ++v2[s2[j]];
        //     if(j - i + 1 == s1.size()) {
        //         if(v1 == v2) {
        //             return true;
        //         } else {
        //             --v2[s2[i]];
        //             ++i;
        //         }
        //     }
        // }
        
        // another writing
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        
        for(int i = 0; i < n1; ++i) {
            ++v1[s1[i]];
            ++v2[s2[i]];
        }
        if(v1 == v2) return true;
        for(int i = n1; i < n2; ++i) {
            ++v2[s2[i]];
            --v2[s2[i - n1]];
            if(v1 == v2) return true;
        }

        return false;
    }
};
// @lc code=end

