package search_in_rotated_sorted_array

func search(nums []int, target int) int {
	return searchInSubArr(nums, 0, len(nums), target)
}

func searchInSubArr(nums []int, lo int, hi int, target int) int {
	if hi-lo == 1 {
		if target == nums[lo] {
			return lo
		}
		return -1
	}
	mi := (lo + hi) / 2
	// 1. 左半区间
	// 1.1. 左半区间有序
	if nums[mi-1] >= nums[lo] {
		// 1.1.1. 在左半区间
		if target >= nums[lo] && target <= nums[mi-1] {
			return searchInSubArr(nums, lo, mi, target)
		}
		// 1.1.2. 在右半区间
		return searchInSubArr(nums, mi, hi, target)
	}
	// 1.2. 左半区间无序，右半区间必有序
	// 1.2.1. 在右半区间
	if target >= nums[mi] && target <= nums[hi-1] {
		return searchInSubArr(nums, mi, hi, target)
	}
	// 1.2.2. 在左半区间
	return searchInSubArr(nums, lo, mi, target)
}
