package valid_parentheses

func isValid(s string) bool {
	if len(s)%2 > 0 {
		return false
	}

	leftMatcher := map[string]string{
		"(": ")",
		"[": "]",
		"{": "}",
	}
	rightMatcher := map[string]string{
		")": "(",
		"]": "[",
		"}": "{",
	}
	leftStack := ""

	for i := 0; i < len(s); i++ {
		elem := s[i : i+1]
		if _, ok := leftMatcher[elem]; ok {
			leftStack += elem
			continue
		}

		if expectedLeft, ok := rightMatcher[elem]; ok {
			if len(leftStack) == 0 || leftStack[len(leftStack)-1:] != expectedLeft {
				return false
			}
			leftStack = leftStack[:len(leftStack)-1]
			continue
		}

		return false
	}

	return len(leftStack) == 0
}
