package set_matrix_zeroes

func setZeroes(matrix [][]int) {
	if len(matrix) == 0 {
		return
	}
	x, y := make([]bool, len(matrix[0])), make([]bool, len(matrix))
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j] == 0 {
				x[j] = true
				y[i] = true
			}
		}
	}
	for i, elem := range x {
		if elem {
			for j := 0; j < len(matrix); j++ {
				matrix[j][i] = 0
			}
		}
	}
	for i, elem := range y {
		if elem {
			for j := 0; j < len(matrix[0]); j++ {
				matrix[i][j] = 0
			}
		}
	}
}
