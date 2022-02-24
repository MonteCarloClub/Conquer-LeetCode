package shortest_unsorted_continuous_subarray

import (
	"sort"
)

func findUnsortedSubarray(nums []int) int {
	sortedNums := append([]int{}, nums...)
	sort.Ints(sortedNums)
	lo, hi := 0, len(nums)-1
	for lo < len(nums) {
		if nums[lo] != sortedNums[lo] {
			break
		}
		lo++
	}
	for hi >= lo {
		if nums[hi] != sortedNums[hi] {
			break
		}
		hi--
	}
	return hi - lo + 1
}
