package is_unique

func isUnique(astr string) bool {
	elemMap := make(map[string]bool)
	for i := 0; i < len(astr); i++ {
		if _, ok := elemMap[astr[i:i+1]]; ok {
			return false
		}
		elemMap[astr[i:i+1]] = true
	}
	return true
}
