package editDistance

/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

// DP

// DP[i][j]: word1 from 0 to i, word2 from 0 to j

func minDistance(word1 string, word2 string) int {
	min3 := func(a, b, c int) int {
		if a <= b && a <= c { return a }
		if b <= c && b <= a { return b }
		return c
	}

	N1 := len(word1)
	N2 := len(word2)
	
	if 0 == N1 { return N2 }
	if 0 == N2 { return N1 }

	DP := make([][]int, N1 + 1)
	for i := 0; i < len(DP); i++ {
		DP[i] = make([]int, N2 + 1)
	}

	for i := 0; i < len(DP); i++ {
		DP[i][0] = i
	}

	for j := 0; j < len(DP[0]); j++ {
		DP[0][j] = j
	}

	for i := 1; i <= N1; i++ {
		for j := 1; j <= N2; j++ {
			if word1[i-1] == word2[j-1] {
				DP[i][j] = DP[i-1][j-1]
			} else {
				DP[i][j] = min3(DP[i-1][j-1], DP[i][j-1], DP[i-1][j]) + 1
			}
		}
	}

	return DP[N1][N2]
}