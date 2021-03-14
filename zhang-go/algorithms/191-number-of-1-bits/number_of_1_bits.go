package number_of_1_bits

func hammingWeight(num uint32) int {
	n := num
	n = round(n, 0)
	n = round(n, 1)
	n = round(n, 2)
	n = round(n, 3)
	n = round(n, 4)
	return int(n)
}

func pow(c uint32) uint32 {
	return 1 << c
}

func mask(c uint32) uint32 {
	return 0xffffffff / (pow(pow(c)) + 1)
}

func round(n uint32, c uint32) uint32 {
	return (n & mask(c)) + (n >> pow(c) & mask(c))
}
