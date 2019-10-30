/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h = 0; h < 12; ++h) {
            for(int m = 0; m < 60; ++m) {
               if(bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
               } 
            }
        }
        return res;
    }
    // vector<string> readBinaryWatch(int num) {
    //     vector<int> hour = {1, 2, 4, 8};
    //     vector<int> min = {1, 2, 4, 8, 16, 32};
    //     vector<string> res;

    //     for(int i = 0; i <= num; ++i) {
    //         int j = num - i;
    //         vector<int> all_h;
    //         vector<int> all_min;

    //         helper(all_h, hour, 0, 0, i);
    //         helper(all_min, min, 0, 0, j);

    //         for(auto& h : all_h) {
    //             if(h > 11) continue;
    //             for(auto& min : all_min) {
    //                 if(min > 59) continue;
    //                 res.push_back(to_string(h) + (min < 10 ? ":0" : ":") + to_string(min));
    //             }
    //         }
    //     }
    //     return res;
    // }

	// void helper(vector<int>& ans, vector<int>& nums, int sum, int start, int N) {
	// 	if (0 == N) {
	// 		ans.push_back(sum);
	// 		return;
	// 	}

	// 	for (int i = start; i < nums.size(); ++i) {
	// 		helper(ans, nums, sum + nums[i], i + 1, N - 1);
	// 	}
	// }
};
// @lc code=end

