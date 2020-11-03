package qing_wa_tiao_tai_jie_wen_ti

func numWays(n int) int {
	const (
		bigNum = 1e9 + 7
	)
	f, g := 1, 1
	_n := n
	for _n > 1 {
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
