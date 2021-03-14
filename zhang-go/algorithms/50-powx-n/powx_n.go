package powx_n

func myPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	if x < 0 {
		if n%2 == 0 {
			if n < 0 {
				return 1 / pow2power(-x, -n)
			}
			return pow2power(-x, n)
		}
		if n < 0 {
			return -1 / pow2power(-x, -n)
		}
		return -pow2power(-x, n)
	}
	if n < 0 {
		return 1 / pow2power(x, -n)
	}
	return pow2power(x, n)
}

func pow2power(x float64, n int) float64 {
	if n == 1 {
		return x
	}
	result := pow2power(x, n>>1)
	if n%2 == 0 {
		return result * result
	}
	return x * result * result
}
