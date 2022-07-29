package next_permutation

func nextPermutation(nums []int) {
	lenOfNums := len(nums)
	i := lenOfNums - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}

	if i >= 0 {
		j := lenOfNums - 1
		for j >= 0 && nums[i] >= nums[j] {
			j--
		}
		nums[i], nums[j] = nums[j], nums[i]
	}
	reverse(nums, i+1, lenOfNums)
}

func reverse(nums []int, lo int, hi int) {
	for i := lo; i < (lo+hi)/2; i++ {
		nums[i], nums[lo+hi-i-1] = nums[lo+hi-i-1], nums[i]
	}
}
