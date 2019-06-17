/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:
	// 不能重复出现，那么需要记录哪些元素已经被遍历过
	void BackTrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& out, vector<int>& visited, int level) {
		if (level == nums.size()) {
			result.push_back(out);
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (1 == visited[i]) continue;

			visited[i] = 1;
			out.emplace_back(nums[i]);
			BackTrack(result, nums, out, visited, level + 1);
			visited[i] = 0;
			out.pop_back();
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int>out, visited(nums.size(), 0);

		BackTrack(result, nums, out, visited, 0);

		return result;
	}
};


class Solution {
public:

	vector<int> remove(vector<int>& nums, int x) {
		vector<int> result;
		for (auto& num_ : nums) {
			if (num_ != x) {
				result.emplace_back(num_);
			}
		}
		return result;
	}

	// 对于S里的每个x，递归的生成S-x的所有排列的序列，而后将x加入到每个序列的前面
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty()) return {};

		vector<vector<int>> result;
		for (auto& num : nums) {
            auto sub = remove(nums, num);
			auto res = permute(sub);

			if (res.empty()) {
				result.push_back({ num });
			}
			else {
				for (auto& ele : res) {
					ele.insert(ele.begin(), num);
					result.push_back(ele);
				}
			}
		}

		return result;
	}
};
