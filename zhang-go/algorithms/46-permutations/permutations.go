package permutations

var results [][]int

func permute(nums []int) [][]int {
	results = make([][]int, 0)
	backtrack(nums, 0, make([]int, 0))
	return results
}

func backtrack(nums []int, rank int, result []int) {
	if rank == len(nums) {
		results = append(results, result)
		return
	}

	for i := 0; i <= rank; i++ {
		nextResult := append(make([]int, 0), result...)
		nextResult = append(nextResult, nums[rank])
		nextResult[i], nextResult[rank] = nextResult[rank], nextResult[i]
		backtrack(nums, rank+1, nextResult)
	}
}
