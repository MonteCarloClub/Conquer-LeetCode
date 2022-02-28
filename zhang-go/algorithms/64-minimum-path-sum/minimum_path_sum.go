package minimum_path_sum

func minPathSum(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	var minPathSumInGrid [][]int
	minPathSumInGrid = make([][]int, len(grid))
	for i := 0; i < len(grid); i++ {
		minPathSumInGrid[i] = make([]int, len(grid[0]))
	}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if i == 0 && j == 0 {
				minPathSumInGrid[i][j] = grid[i][j]
				continue
			}
			if i == 0 {
				minPathSumInGrid[i][j] = minPathSumInGrid[i][j-1] + grid[i][j]
				continue
			}
			if j == 0 {
				minPathSumInGrid[i][j] = minPathSumInGrid[i-1][j] + grid[i][j]
				continue
			}
			minPathSumInGrid[i][j] = min(minPathSumInGrid[i][j-1]+grid[i][j],
				minPathSumInGrid[i-1][j]+grid[i][j])
		}
	}
	return minPathSumInGrid[len(grid)-1][len(grid[0])-1]
}

func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
