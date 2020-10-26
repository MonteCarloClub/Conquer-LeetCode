package zigzag_conversion

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	var sol string
	for i := 0; i < numRows; i++ {
		r := i
		if i == 0 || i == numRows-1 {
			for r < len(s) {
				sol += s[r : r+1]
				r += 2 * (numRows - 1)
			}
		} else {
			for r < len(s) {
				sol += s[r : r+1]
				if r+2*(numRows-i-1) < len(s) {
					sol += s[r+2*(numRows-i-1) : r+2*(numRows-i-1)+1]
				}
				r += 2 * (numRows - 1)
			}
		}
	}
	return sol
}
