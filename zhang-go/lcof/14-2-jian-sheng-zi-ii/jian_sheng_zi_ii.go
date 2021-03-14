package jian_sheng_zi_ii

func cuttingRope(n int) int {
	if n <= 3 {
		return n - 1
	}
	a := n / 3
	b := n % 3
	if b == 0 {
		return getRemainder(1, a)
	}
	if b == 1 {
		return getRemainder(4, a-1)
	}
	return getRemainder(2, a)
}

func getRemainder(x int, y int) int {
	LargePrimeNumber := 1000000007
	// result=x*3^y
	remainder := x
	for i := 1; i <= y; i++ {
		remainder *= 3
		if remainder > LargePrimeNumber {
			remainder %= LargePrimeNumber
		}
	}
	return remainder
}
