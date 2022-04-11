package maximum_subarray

func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	results := make([]int, len(nums))
	results[0] = nums[0]
	result := nums[0]
	for i := 1; i < len(nums); i++ {
		results[i] = max(results[i-1]+nums[i], nums[i])
		result = max(result, results[i])
	}
	return result
}

func max(x int, y int) int {
	if x < y {
		return y
	}
	return x
}
