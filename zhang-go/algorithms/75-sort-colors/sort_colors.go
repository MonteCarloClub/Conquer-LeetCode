package sort_colors

func sortColors(nums []int) {
	lo := 0
	flag := 0
	for flag < len(nums) {
		if nums[flag] == 0 {
			nums[lo], nums[flag] = nums[flag], nums[lo]
			lo++
		}
		flag++
	}

	hi := len(nums) - 1
	flag = hi
	for flag >= lo {
		if nums[flag] == 2 {
			nums[hi], nums[flag] = nums[flag], nums[hi]
			hi--
		}
		flag--
	}
}
