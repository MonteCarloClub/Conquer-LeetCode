package subsets

func getSubset(nums []int, flag int) []int {
	var result []int
	for i := 0; i < len(nums); i++ {
		if ((flag<<(len(nums)-i-1))>>(len(nums)-1))&1 == 0 {
			continue
		}
		result = append(result, nums[i])
	}
	return result
}

func subsets(nums []int) [][]int {
	var results [][]int
	for i := 0; i < 1<<len(nums); i++ {
		results = append(results, getSubset(nums, i))
	}
	return results
}
