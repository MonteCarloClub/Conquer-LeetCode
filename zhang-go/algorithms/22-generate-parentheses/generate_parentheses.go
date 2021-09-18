package generate_parentheses

func generateParenthesis(n int) []string {
	results := make([][]string, n+1)
	results[0] = append(results[0], "")
	for i := 1; i <= n; i++ {
		for j := 0; j <= i-1; j++ {
			for _, strInParenthesis := range results[j] {
				for _, strOutParenthesis := range results[i-j-1] {
					results[i] = append(results[i], "("+strInParenthesis+")"+strOutParenthesis)
				}
			}
		}
	}
	return results[n]
}
