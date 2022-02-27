package find_minimum_in_rotated_sorted_array

func findMin(nums []int) int {
	return findMinInSubArr(nums, 0, len(nums))
}

func findMinInSubArr(nums []int, lo int, hi int) int {
	if hi-lo == 1 {
		return nums[lo]
	}
	if hi-lo == 2 {
		return min(nums[lo], nums[lo+1])
	}
	mi := (lo + hi) / 2
	if nums[mi] < nums[hi-1] {
		return findMinInSubArr(nums, lo, mi+1)
	}
	return findMinInSubArr(nums, mi, hi)
}

func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
