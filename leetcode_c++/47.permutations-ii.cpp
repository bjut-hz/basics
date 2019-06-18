/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
// 思路：统计每个数的数量，然后对于每个相同的数根据数量情况加入到结果中去
class Solution {
public:
	using MapIter = map<int, int>::const_iterator;

	void BackTrack(MapIter start, MapIter end, vector<vector<int>>& result, vector<int>& out, int N) {
		if (out.size() >= N) {
			result.push_back(out);
			return;
		}
		// 扩展状态
		for (auto iter = start; iter != end; ++iter) {
			int count = 0;
			for (auto& num : out) {
				if (iter->first == num) {
					++count;
				}
			}

			if (count < iter->second) {
				out.push_back(iter->first);
				BackTrack(start, end, result, out, N);
				out.pop_back();
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		map<int, int> counter;
		for_each(nums.begin(), nums.end(), [&counter](int e) {
			if (counter.find(e) != counter.end()) {
				++counter[e];
			}
			else {
				counter[e] = 1;
			}
		});

		vector<vector<int>> result;
		vector<int> out;

		BackTrack(counter.begin(), counter.end(), result, out, nums.size());

		return result;
	}
};

