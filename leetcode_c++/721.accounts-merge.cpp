/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> root;
        map<string, string> owner;

        for(auto& account : accounts) {
            for(int i = 1; i < account.size(); ++i) {
                root[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }

        // 把所有相同帐号的邮箱都链接在一起了,最终为最后一个被合并帐号的第一个邮箱的父串p
        for(auto& account : accounts) {
            auto p = find(root, account[1]);
            for(int i = 2; i < account.size(); ++i) {
                root[find(root, account[i])] = p;
            }
        }

        map<string, set<string>> m;
        for(auto& account : accounts) {
            for(int i = 1; i < account.size(); ++i) {
                m[find(root, account[i])].insert(account[i]);
            }
        }

        vector<vector<string>> ans;
        for(auto a : m) {
            vector<string> v(a.second.begin(), a.second.end());
            v.insert(v.begin(), owner[a.first]);
            ans.push_back(v);
        }

        return ans;
    }

    string find(map<string, string>& root, string key) {
        return root[key] == key ? key : find(root, root[key]);
    }
};
// @lc code=end

