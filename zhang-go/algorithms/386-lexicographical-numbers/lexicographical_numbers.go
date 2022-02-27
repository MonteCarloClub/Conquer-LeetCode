package lexicographical_numbers

var (
	result []int
)

func lexicalOrder(n int) []int {
	result = make([]int, 0)
	for i := 1; i <= 9; i++ {
		dfs(i, n)
	}
	return result
}

func dfs(x int, n int) {
	if x > n {
		return
	}
	result = append(result, x)
	for i := 10 * x; i <= 10*x+9; i++ {
		dfs(i, n)
	}
}
