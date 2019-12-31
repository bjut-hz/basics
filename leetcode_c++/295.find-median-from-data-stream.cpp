/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (39.77%)
 * Likes:    1642
 * Dislikes: 32
 * Total Accepted:    142.6K
 * Total Submissions: 358.7K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

// @lc code=start
// class MedianFinder {
// public:
//     /** initialize your data structure here. */
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         int i = 0;
//         for(i = 0; i < nums_.size(); ++i) {
//             if(num <= nums_[i]) {
//                 break;
//             }
//         }
//         nums_.insert(nums_.begin() + i, num);
//     }
    
//     double findMedian() {
//         if(nums_.empty()) return 0;

//         int n = nums_.size();
//         if(n & 1) {
//             return nums_[n / 2];
//         } else {
//             return (double)(nums_[n / 2 - 1] + nums_[n / 2]) / 2;
//         }
//     }

// private:
//     vector<int> nums_;
// };

// 使用堆来保持数字的有序性,为了方便得到中位数,使用两个堆来保存数据,一半一半的保存
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap_.push(num);
        max_heap_.push(min_heap_.top());
        min_heap_.pop();

        if(min_heap_.size() < max_heap_.size()) {
            min_heap_.push(max_heap_.top());
            max_heap_.pop();
        }
    }
    
    double findMedian() {
        if(min_heap_.size() > max_heap_.size()) {
            return min_heap_.top();
        } else {
            return 0.5 * (min_heap_.top() + max_heap_.top());
        }
    }

private:
    priority_queue<long, vector<long>, greater<long>> min_heap_;
    priority_queue<long, vector<long>, less<long>> max_heap_;
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

