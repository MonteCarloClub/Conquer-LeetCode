package da_yin_cong_1dao_zui_da_de_nwei_shu

func printNumbers(n int) []int {
	hi := 1
	for i := 0; i < n; i++ {
		hi *= 10
	}
	result := []int{}
	for i := 1; i < hi; i++ {
		result = append(result, i)
	}
	return result
}
