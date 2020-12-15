package search_a_2d_matrix_ii

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	if len(matrix[0]) == 0 {
		return false
	}
	lo := searchRowByRightEnd(matrix, target, 0, len(matrix))
	hi := searchRowByLeftEnd(matrix, target, 0, len(matrix))
	if hi-lo > 0 {
		for i := lo; i < hi; i++ {
			if searchInRow(matrix[i], target, 0, len(matrix[0])) {
				return true
			}
		}
	}
	return false
}

func searchRowByLeftEnd(matrix [][]int, target int, lo int, hi int) int {
	if lo == hi {
		return lo /* >target的最小秩r，目标值在[0, r)搜索 */
	}
	mi := (lo + hi) / 2
	if matrix[mi][0] <= target {
		return searchRowByLeftEnd(matrix, target, mi+1, hi)
	}
	return searchRowByLeftEnd(matrix, target, lo, mi)
}

func searchRowByRightEnd(matrix [][]int, target int, lo int, hi int) int {
	if lo == hi {
		return lo /* >=target的最小秩r，目标值在[r, len)搜索 */
	}
	mi := (lo + hi) / 2
	if matrix[mi][len(matrix[0])-1] < target {
		return searchRowByRightEnd(matrix, target, mi+1, hi)
	}
	return searchRowByRightEnd(matrix, target, lo, mi)
}

func searchInRow(row []int, target int, lo int, hi int) bool {
	if hi-lo == 1 {
		return row[lo] == target
	}
	mi := (lo + hi) / 2
	if row[mi] <= target {
		return searchInRow(row, target, mi, hi)
	}
	return searchInRow(row, target, lo, mi)
}
