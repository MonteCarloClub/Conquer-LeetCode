package combination_sum

func combinationSum(candidates []int, target int) (results [][]int) {
	result := []int{}
	var dfs func(target, r int)
	dfs = func(target, r int) {
		if r == len(candidates) {
			return
		}

		if target == 0 {
			results = append(results, append([]int(nil), result...))
			return
		}

		dfs(target, r+1)

		if target-candidates[r] >= 0 {
			result = append(result, candidates[r])
			dfs(target-candidates[r], r)
			result = result[:len(result)-1]
		}
	}
	dfs(target, 0)
	return
}
