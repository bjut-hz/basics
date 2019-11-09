/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    // // brute force
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     for(int i = 0; i < gas.size(); ++i) {
    //         if(gas[i] >= cost[i]) {
    //             int remaing = gas[i] - cost[i];
    //             int j = (i + 1) % gas.size();
    //             while(j != i) {
    //                 remaing += gas[j] - cost[j];
    //                 if(remaing < 0) break;

    //                 ++j;
    //                 if(j == gas.size()) {
    //                     j = 0;
    //                 }
    //             }

    //             if(remaing >= 0) return i;
    //         }
    //     }

    //     return -1;
    // }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for(int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i]; // 如果从起点到该点值小于0了，说明从起点到这一站点中间任何一个点都不能作为起始点，因为跟本到不了该站点了

            if(sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }

        return total >= 0 ? start : -1;
    }
};
// @lc code=end

