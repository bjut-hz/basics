/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
private:
    stack<int>      stk_;
    stack<int>      min_stk_;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        stk_.push(x);
        if(min_stk_.empty() || x <= min_stk_.top()) {
            min_stk_.push(x);
        }
    }
    
    void pop() {
        if(!stk_.empty()) {
            if(!min_stk_.empty() && min_stk_.top() == stk_.top()) {
                min_stk_.pop();
            }
            stk_.pop();
        }
    }
    
    int top() {
        return stk_.top();
    }
    
    int getMin() {
        return min_stk_.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

