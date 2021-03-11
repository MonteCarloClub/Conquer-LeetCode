package find_minimum_in_rotated_sorted_array_ii

func findMin(nums []int) int {
	return findMinInInterval(nums, 0, len(nums))
}

func findMinInInterval(nums []int, lo int, hi int) int {
	if hi-lo == 1 {
		return nums[lo]
	}
	if hi-lo == 2 {
		if nums[lo] < nums[lo+1] {
			return nums[lo]
		}
		return nums[lo+1]
	}
	mi := (lo + hi) >> 1
	if nums[mi] < nums[hi-1] {
		return findMinInInterval(nums, lo, mi+1)
	}
	if nums[mi] == nums[hi-1] {
		return findMinInInterval(nums, lo, hi-1)
	}
	return findMinInInterval(nums, mi+1, hi)
}
