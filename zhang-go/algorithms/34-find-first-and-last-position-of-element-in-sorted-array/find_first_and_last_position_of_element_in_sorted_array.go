package find_first_and_last_position_of_element_in_sorted_array

func searchRange(nums []int, target int) []int {
	if nums == nil || len(nums) == 0 {
		return []int{-1, -1}
	}
	var left, right int

	left = searchInArray(nums, 0, len(nums), target)
	if left == -1 || nums[left] != target {
		return []int{-1, -1}
	}

	right = searchInArray(nums, 0, len(nums), target+1)
	if right == -1 {
		right = len(nums) - 1
	} else {
		right -= 1
	}

	return []int{left, right}
}

// searchInArray 返回 [lo, hi) 中 >= target 元素的最小秩
// 当 target 比全体元素大时，返回 -1
func searchInArray(nums []int, lo int, hi int, target int) int {
	if hi-lo == 1 {
		if nums[lo] >= target {
			return lo
		} else {
			return -1
		}
	}

	mi := (lo + hi) / 2
	resultOfLeft := searchInArray(nums, lo, mi, target)
	resultOfRight := searchInArray(nums, mi, hi, target)

	if resultOfLeft == -1 {
		return resultOfRight
	}
	return resultOfLeft
}
