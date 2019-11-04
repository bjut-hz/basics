/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        const int N = A.size();
        if(N <= 1) return N;

        // if all num is same
        int i = 0;
        for(i = 1; i < A.size(); ++i) {
            if(A[i] != A[i-1]) {
                break;
            }
        }
        if(i == N) return 1;

        int cnt = 2;
        int res = 2;
        for(int i = 1; i < A.size() - 1; ++i) {
            if(A[i-1] < A[i] && A[i] > A[i+1]) {
                ++cnt;
            } else if(A[i-1] > A[i] && A[i] < A[i+1]) {
                ++cnt;
            } else {
                cnt = 2;
            }

            res = max(cnt, res);
        }

        return res;
    }
};
// @lc code=end

