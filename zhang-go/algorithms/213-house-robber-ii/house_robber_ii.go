package house_robber_ii

func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	if len(nums) == 2 {
		return max(nums[0], nums[1])
	}
	return max(robInRange(nums[:len(nums)-1]), robInRange(nums[1:]))
}

func robInRange(nums []int) int {
	left, right := nums[0], max(nums[0], nums[1])
	for i := 2; i < len(nums); i++ {
		left, right = right, max(left+nums[i], right)
	}
	return right
}

func max(x int, y int) int {
	if x < y {
		return y
	}
	return x
}
