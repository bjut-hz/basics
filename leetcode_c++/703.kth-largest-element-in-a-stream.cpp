/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (auto& num : nums) {
			if (pq.empty()) {
				pq.push(num);
			} else {
				if (pq.size() == k) {
					if (num > pq.top()) {
						pq.pop();
					} else {
						continue;
					}
				}

				pq.push(num);
			}
		}
    }
    
    int add(int val) {
        if(pq.size() < k_) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

