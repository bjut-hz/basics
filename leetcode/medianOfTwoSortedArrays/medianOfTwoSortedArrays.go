package medianOfTwoSortedArrays

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

func min2(a, b int) int {
	if a < b { return a }
	return b
}

func findKth(nums1 []int, nums2 []int, K int) int {
	if len(nums1) > len(nums2) {
		return findKth(nums2, nums1, K)
	}

	if len(nums1) == 0 { return nums2[K-1] }
	if K == 1 { return min2(nums1[0], nums2[0]) }

	p := min2(K/2, len(nums1))
	q := K - p
	if nums1[p-1] == nums2[q-1] {
		return nums1[p-1]
	} else if nums1[p-1] > nums2[q-1] {
		return findKth(nums1, nums2[q:], K-q)
	} else {
		return findKth(nums1[p:], nums2, K-p)
	}
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	length := len(nums1) + len(nums2)
	if 1 == length & 0x01 {
		// odd
		return float64(findKth(nums1, nums2, length / 2 + 1))
	} else {
		return  float64(findKth(nums1, nums2, length / 2) + findKth(nums1, nums2, length / 2 + 1)) / 2
	}
}