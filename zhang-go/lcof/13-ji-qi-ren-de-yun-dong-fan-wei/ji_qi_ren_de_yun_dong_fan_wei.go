package ji_qi_ren_de_yun_dong_fan_wei

func movingCount(m int, n int, k int) int {
	visitedGrid := make([][]bool, m)
	for i := 0; i < m; i++ {
		visitedGrid[i] = make([]bool, n)
	}
	return countOfAccessibleGrid(0, 0, m, n, k, &visitedGrid)
}

func isAccessible(x int, y int, m int, n int, k int, visitedGrid *[][]bool) bool {
	// 1 <= x,y <= 100
	return x >= 0 && x < m && y >= 0 && y < n && x/10+x%10+y/10+y%10 <= k && !(*visitedGrid)[x][y]
}

func countOfAccessibleGrid(x int, y int, m int, n int, k int, visitedGrid *[][]bool) int {
	if isAccessible(x, y, m, n, k, visitedGrid) {
		(*visitedGrid)[x][y] = true
		return 1 + countOfAccessibleGrid(x-1, y, m, n, k, visitedGrid) + countOfAccessibleGrid(x+1, y, m, n, k, visitedGrid) + countOfAccessibleGrid(x, y-1, m, n, k, visitedGrid) + countOfAccessibleGrid(x, y+1, m, n, k, visitedGrid)
	}
	return 0
}
