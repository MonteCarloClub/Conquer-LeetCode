package fibonacci_number

func fib(N int) int {
	f, g := 1, 0
	n := N
	for n > 0 {
		n--
		g = g + f
		f = g - f
	}
	return g
}
