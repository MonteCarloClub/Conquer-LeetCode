package find_minimum_in_rotated_sorted_array_ii

import (
	"fmt"
	"math/rand"
	"sort"
	"strconv"
	"testing"
	"time"
)

func TestFindMin(t *testing.T) {
	for {
		rotatedArray, minElem := genRandomArray(10, 25)
		myMinElem := findMin(rotatedArray)
		if myMinElem != minElem {
			t.Errorf("A sample that failed the test was captured!")
			fmt.Println("INPUT:")
			fmt.Println(rotatedArray)
			fmt.Println("OUTPUT:")
			fmt.Println("Key: " + strconv.Itoa(minElem) + "\tSolution: " + strconv.Itoa(myMinElem))
			return
		}
	}
}

func genRandomArray(maxElem int, maxLen int) ([]int, int) {
	rand.Seed(time.Now().UnixNano())
	var len int
	len = rand.Intn(maxLen) + 1
	array := make([]int, len)
	for i := 0; i < len; i++ {
		array[i] = rand.Intn(maxElem)
	}
	sort.Ints(array)
	fmt.Println(array)
	minElem := array[0]
	pivot := rand.Intn(len)
	rotatedArray := make([]int, len)
	for i := 0; i < len; i++ {
		if i < len-pivot {
			rotatedArray[i] = array[i+pivot]
		} else {
			rotatedArray[i] = array[i+pivot-len]
		}
	}
	return rotatedArray, minElem
}
