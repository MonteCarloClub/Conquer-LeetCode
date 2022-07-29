package find_first_and_last_position_of_element_in_sorted_array

import (
	"fmt"
	"testing"
)

func TestSearchInArray(t *testing.T) {
	nums := []int{0, 0, 1, 2, 2, 3, 5, 5, 5, 7}
	fmt.Println(searchInArray(nums, 0, 10, 0)) // 0
	fmt.Println(searchInArray(nums, 1, 9, 1))  // 2
	fmt.Println(searchInArray(nums, 0, 10, 4)) // 6
	fmt.Println(searchInArray(nums, 0, 10, 7)) // 9
	fmt.Println(searchInArray(nums, 0, 10, 8)) // -1
}
