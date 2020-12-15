package fei_bo_na_qi_shu_lie

func fib(n int) int {
	const (
		bigNum = 1e9 + 7
	)
	f, g := 1, 0
	_n := n
	for _n > 0 {
		_n--
		g = g + f
		f = g - f
		if g >= bigNum {
			g %= bigNum
			f %= bigNum
		}
	}
	return g
}
