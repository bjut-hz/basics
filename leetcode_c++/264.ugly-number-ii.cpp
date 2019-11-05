/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    // // 每个丑陋数乘以2，3，5会得到新的丑陋数，但是得到的数不是按顺序的
    // int nthUglyNumber(int n) {
    //     vector<int> res(1, 1);
    //     int i2 = 0, i3 = 0, i5 = 0; // index denote which ugly number should use
    //     while(res.size() < n) {
    //         // get next ugly number
    //         int mn = min(min(res[i2] * 2, res[i3] * 3), res[i5] * 5);
    //         res.push_back(mn);


    //         if(mn == res[i2] * 2) {
    //             ++i2;
    //         }

    //         if(mn == res[i3] * 3) {
    //             ++i3;
    //         }

    //         if(mn == res[i5] * 5) {
    //             ++i5;
    //         }
    //     }
    //     return res.back();
    // }

    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        q.push(1);

        for(int i = 1; i < n; ++i) {
            auto tmp = q.top();
            q.pop();

            while(!q.empty() && tmp == q.top()) {
                q.pop();
            }

            q.push(tmp * 2);
            q.push(tmp * 3);
            q.push(tmp * 5);
        }
        return q.top();
    }
};
// @lc code=end

