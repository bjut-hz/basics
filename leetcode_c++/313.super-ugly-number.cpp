/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
class Solution {
public:
    // int nthSuperUglyNumber(int n, vector<int>& primes) {
    //     priority_queue<long long, vector<long long>, greater<long long>> pq;
    //     pq.push(1);

    //     for(int i = 1; i < n; ++i) {
    //         auto tmp = pq.top();
    //         pq.pop();

    //         while(!pq.empty() && tmp == pq.top()) {
    //             pq.pop();
    //         }

    //         for(auto& num : primes) {
    //             pq.push(tmp * num);
    //         }
    //     }

    //     return pq.top();
    // }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1, 1);

        vector<int> idx(primes.size(), 0);
        while(res.size() < n) {
            int mn = INT_MAX;

            for(int i = 0; i < primes.size(); ++i) {
                if(primes[i] * res[idx[i]] < mn) {
                    mn = primes[i] * res[idx[i]];
                }
            }

            res.push_back(mn);

            for(int i = 0; i < primes.size(); ++i) {
                if(primes[i] * res[idx[i]] == mn) {
                    ++idx[i];
                }
            }
        }

        return res.back();
    }
};
// @lc code=end

