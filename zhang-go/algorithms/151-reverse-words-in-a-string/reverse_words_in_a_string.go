package reverse_words_in_a_string

import (
	"fmt"
)

func reverseWords(s string) string {
	result := ""
	resultInSlice := make([]string, 0)
	lo := 0
	for lo < len(s) {
		if s[lo:lo+1] == " " {
			lo++
			continue
		}
		hi := lo + 1
		for hi < len(s) && s[hi:hi+1] != " " {
			hi++
		}
		if s[hi-1:hi] != " " {
			resultInSlice = append(resultInSlice, s[lo:hi])
		}
		lo = hi + 1
	}
	for i := len(resultInSlice) - 1; i >= 0; i-- {
		result += fmt.Sprintf(" %s", resultInSlice[i])
	}
	return result[1:]
}
