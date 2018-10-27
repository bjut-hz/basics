package courseSchedule


import "container/list"

/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

// use topsort detect if there is a cycle in graph
func canFinish(numCourses int, prerequisites [][]int) bool {
	indegree := make([]int, numCourses, numCourses)
	graph := make(map[int][]int, numCourses)
	//use adjacency list
	for _, pair := range prerequisites {
		indegree[pair[0]]++
		if _, ok := graph[pair[1]]; !ok {
			graph[pair[1]] = make([]int, 0, numCourses)
		}
		graph[pair[1]] = append(graph[pair[1]], pair[0])
	}

	queue := list.New()
	for i, v := range indegree {
		if 0 == v {
			queue.PushBack(i)
		}
	}

	counter := 0
	for 0 != queue.Len() {
		element := queue.Front()
		queue.Remove(element)
		counter++

		vertex := element.Value.(int)
		for _, v := range graph[vertex] {
			indegree[v]--
			if 0 == indegree[v] {
				queue.PushBack(v)
			}
		}
	}

	if numCourses != counter {
		return false
	}

	return true
}