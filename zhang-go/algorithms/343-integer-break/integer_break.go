package integer_break

func integerBreak(n int) int {
	results := make([]int, n+1)
	results[1] = 1
	for i := 2; i <= n; i++ {
		for j := 1; j < i; j++ {
			results[i] = max(results[i], max(j*(i-j), j*results[i-j]))
		}
	}
	return results[n]
}

func max(x int, y int) int {
	if x < y {
		return y
	}
	return x
}
