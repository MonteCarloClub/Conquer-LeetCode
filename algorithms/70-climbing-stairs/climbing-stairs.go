package climbing_stairs

func climbStairs(n int) int {
	f, g := 1, 1
	_n := n
	for _n > 1 {
		_n--
		g = g + f
		f = g - f
	}
	return g
}
