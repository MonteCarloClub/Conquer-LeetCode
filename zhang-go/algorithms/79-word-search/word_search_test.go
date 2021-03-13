package word_search

import (
	"fmt"
	"testing"
)

func TestExist(t *testing.T) {
	board := [][]byte{
		{65, 66, 67, 69},
		{83, 70, 69, 83},
		{65, 68, 69, 69},
	}
	word := "ABCESEEEFS"
	fmt.Println(exist(board, word))
}
