/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (50.28%)
 * Likes:    1245
 * Dislikes: 520
 * Total Accepted:    137K
 * Total Submissions: 272.6K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns
 * false, 
 * the order of elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns
 * false, 
 * the order of elements returned by next should be: [1,4,6].
 * 
 * 
 * 
 * 
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = int(nestedList.size()) - 1; i >= 0; --i) {
            stk_.push(nestedList[i]);
        }
    }

    int next() {
        auto& t = stk_.top();
        stk_.pop();

        return t.getInteger();
    }

    bool hasNext() {
    //     if(stk_.empty()) return false;

    //     auto t = stk_.top();
    //     while(!t.isInteger()) {
    //         auto itegers = t.getList();
    //         stk_.pop();

    //         for(int i = int(itegers.size()) - 1; i >= 0; --i) {
    //             stk_.push(itegers[i]);
    //         }

    //         if(stk_.empty()) return false;
    //         t = stk_.top();
    //     }

    //     return true;

        while(!stk_.empty()) {
            auto t = stk_.top();
            if(t.isInteger()) return true;
            stk_.pop();
            
            auto integers = t.getList();
            for(int i = integers.size() - 1; i >= 0; --i) {
                stk_.push(integers[i]);
            }
        }
        return false;
    }

private:
    stack<NestedInteger> stk_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

