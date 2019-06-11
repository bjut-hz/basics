/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
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
			// 注意去重的技巧, 对于已经算过的情形直接略过
			if (i > index && candidates[i] == candidates[i - 1]) continue;

			res.push_back(candidates[i]);
			BackTrack(result, candidates, res, target, sum + candidates[i], i + 1);
			res.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> res;
		// 注意此处需要排序，如果不排序，不方便去重。。即使使用set也不能去重，因为不排序，数字的顺序不定导致形成了不同的vector
		sort(candidates.begin(), candidates.end());

		BackTrack(result, candidates, res, target, 0, 0);

		return result;
	}
};

