package divide_two_integers

func divide(dividend int, divisor int) int {
	if dividend == 0 {
		return 0
	}
	if dividend < 0 && divisor < 0 {
		return div(-dividend, -divisor)
	}
	if dividend < 0 && divisor > 0 {
		return -div(-dividend, divisor)
	}
	if dividend > 0 && divisor < 0 {
		return -div(dividend, -divisor)
	}
	return div(dividend, divisor)
}

func div(dividend int, divisor int) int {
	result := 0
	counter := 0
	for counter <= dividend {
		counter += divisor
		result++
	}
	return result - 1
}
