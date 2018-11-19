package mergeIntervals

import "sort"

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/


type Interval struct {
	Start int
	End   int
}

func merge(intervals []Interval) []Interval {
	if 0 == len(intervals) { return []Interval{} }

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i].Start < intervals[j].Start
	})

	result := make([]Interval, 0, len(intervals))
	result = append(result, intervals[0])
	for i := 1; i < len(intervals); i++ {
		if intervals[i].Start <= result[len(result)-1].End {
			if intervals[i].End > result[len(result)-1].End {
				result[len(result)-1].End = intervals[i].End
			}
		} else {
			result = append(result, intervals[i])
		}
	}

	return result
}