package queueReconstructionByHeight

import "sort"

/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int) bool {
		return people[i][0] > people[j][0] || (people[i][0] == people[j][0] && people[i][1] < people[j][1])
	})

	N := len(people)
	result := make([][]int, 0, N)
	for i := 0; i < N; i++ {
		index := people[i][1]
		// insert at
		rear := append([][]int{}, result[index:]...)
		result = append(result[0:index], people[i])
		result = append(result, rear...)
	}

	return result
}