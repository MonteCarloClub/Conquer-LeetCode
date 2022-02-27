package unique_paths

func uniquePaths(m int, n int) int {
	if m == 0 || n == 0 {
		return 0
	}
	countOfUniquePaths := make([][]int, m)
	for i := 0; i < m; i++ {
		countOfUniquePaths[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				countOfUniquePaths[i][j] = 1
			} else {
				countOfUniquePaths[i][j] = countOfUniquePaths[i-1][j] + countOfUniquePaths[i][j-1]
			}
		}
	}
	return countOfUniquePaths[m-1][n-1]
}
