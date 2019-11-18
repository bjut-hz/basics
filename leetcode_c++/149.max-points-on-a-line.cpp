/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    // gcd
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    // 如果用dy/dx算斜率的话，double表示有问题，那么可以求dy dx的最大公约数，保存两个对应的商
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); ++i) {
            map<vector<int>, int> m;

            int duplicate = 1;
            for(int j = i + 1; j < points.size(); ++j) {
                if(points[j] == points[i]) {
                    ++duplicate;
                    continue;
                }

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, duplicate);

            for(auto& ele : m) {
                res = max(res, ele.second + duplicate);
            }
        }

        return res;
    }
};
// @lc code=end

