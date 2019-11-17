/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    // use BFS,一层一层向外部扩大，直至达到目标
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		set<string> s(wordList.begin(), wordList.end());
		if (!s.count(endWord)) return 0;

		queue<string> q;
		q.push(beginWord);
		int res = 0;
		while (!q.empty()) {
			for (int k = q.size(); k > 0; --k) {
				string word = q.front();
				q.pop();
				if (word == endWord) return res + 1;
				for (int i = 0; i < word.size(); ++i) {
					string new_word = word;
					for (char ch = 'a'; ch <= 'z'; ++ch) {
						new_word[i] = ch;

						if (s.count(new_word) && new_word != word) {
							q.push(new_word);
							s.erase(new_word); // 已经处理过的就不要再处理了，否则可能会陷入死循环
						}
					}
				}
			}
			++res;
		}

		return 0;
	}
};
// @lc code=end

