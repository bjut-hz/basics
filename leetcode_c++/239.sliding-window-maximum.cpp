/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     if(0 == k) return {};

    //     auto GetMax = [](vector<int> nums, int l, int r) {
    //         int res = nums[l];
    //         for(int i = l; i <= r; ++i) {
    //             if(nums[i] > res) {
    //                 res = nums[i];
    //             }
    //         }
    //         return res;
    //     };

    //     vector<int> res;
    //     for(int i = 0; i + k <= nums.size(); ++i) {
    //         res.push_back(GetMax(nums, i, i + k - 1));
    //     }

    //     return res;
    // }
    /*
        用双向队列保存数字的下标，遍历整个数组，如果此时队列的首元素是 i-k 的话，
        表示此时窗口向右移了一步，则移除队首元素。然后比较队尾元素和将要进来的值，
        如果小的话就都移除，然后此时我们把队首元素加入结果中即可
    */
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			if (!dq.empty() && dq.front() == (i - k)) {
				dq.pop_front();
			}

            // 保留当前范围内最大的值即可
			while (!dq.empty() && nums[i] > nums[dq.back()]) {
				dq.pop_back();
			}
			dq.push_back(i);

			if (i >= k - 1) {
				res.push_back(nums[dq.front()]);
			}
		}

		return res;
	}
};
// @lc code=end

