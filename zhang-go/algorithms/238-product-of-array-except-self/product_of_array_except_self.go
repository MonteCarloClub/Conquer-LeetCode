package product_of_array_except_self

func productExceptSelf(nums []int) []int {
	if len(nums) == 0 {
		return nil
	}

	L, R := make([]int, len(nums)), make([]int, len(nums))
	result := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		j := len(nums) - i - 1
		if i == 0 {
			L[i] = nums[i]
		} else {
			L[i] = L[i-1] * nums[i]
		}

		if j == len(nums)-1 {
			R[j] = nums[j]
		} else {
			R[j] = R[j+1] * nums[j]
		}
	}

	for i := 0; i < len(nums); i++ {
		if i == 0 {
			result[i] = R[i+1]
			continue
		}
		if i == len(nums)-1 {
			result[i] = L[i-1]
			continue
		}
		result[i] = L[i-1] * R[i+1]
	}
	return result
}
