package nth_digit

import (
	"math"
	"strconv"
)

func findNthDigit(n int) int {
	totalOfDigit := 0
	var countOfDigit int

	for i := 1; i < 10; i++ {
		countOfInterval := 9 * i * int(math.Pow10(i-1))
		if totalOfDigit+countOfInterval >= n {
			countOfDigit = i
			break
		}
		totalOfDigit += countOfInterval
	}

	number := int(math.Pow10(countOfDigit-1)) + (n-totalOfDigit)/countOfDigit - 1
	var rankOfDigit int
	if (n-totalOfDigit)%countOfDigit == 0 {
		rankOfDigit = countOfDigit
	} else {
		rankOfDigit = (n - totalOfDigit) % countOfDigit
		number++
	}
	res, _ := strconv.Atoi(strconv.Itoa(number)[rankOfDigit-1 : rankOfDigit])
	return res
}
