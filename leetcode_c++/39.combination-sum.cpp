/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
	void BackTrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& res, int target, int sum, int index) {
		if (sum > target) return;

		if (target == sum) {
			result.push_back(res);
			return;
		}

		for (int i = index; i < candidates.size(); ++i) {
			res.push_back(candidates[i]);
			BackTrack(result, candidates, res, target, sum + candidates[i], i);
			res.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> res;
		BackTrack(result, candidates, res, target, 0, 0);

		return result;
	}
};

