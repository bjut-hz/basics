package uniqueBinarySearchTrees

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

// 卡塔兰数: https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0
func numTrees(n int) int {
	DP := make([]int, n+1)
	DP[0] = 1
	for i := 0; i < n; i++ {
		for j := 0; j <= i; j++ {
			DP[i+1] += DP[j] * DP[i-j]
		}
	}
	return DP[n]
}