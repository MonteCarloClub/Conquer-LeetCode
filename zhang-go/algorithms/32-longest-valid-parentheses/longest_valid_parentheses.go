package longest_valid_parentheses

func longestValidParentheses(s string) int {
	result := 0
	results := make([]int, len(s))
	for i := 1; i < len(s); i++ {
		if s[i] == '(' {
			continue
		}
		if s[i-1] == '(' {
			if i-2 >= 0 {
				results[i] = results[i-2] + 2
			} else {
				results[i] = 2
			}
		} else {
			lenOfSubStr := results[i-1]
			if i-lenOfSubStr-1 >= 0 && s[i-lenOfSubStr-1] == '(' {
				if i-lenOfSubStr-2 >= 0 {
					results[i] = results[i-1] + results[i-lenOfSubStr-2] + 2
				} else {
					results[i] = results[i-1] + 2
				}
			}
		}
		if results[i] > result {
			result = results[i]
		}
	}
	return result
}
