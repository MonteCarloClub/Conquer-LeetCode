package ti_huan_kong_ge

func replaceSpace(s string) string {
	var sol string
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			sol += "%20"
		} else {
			sol += s[i : i+1]
		}
	}
	return sol
}
