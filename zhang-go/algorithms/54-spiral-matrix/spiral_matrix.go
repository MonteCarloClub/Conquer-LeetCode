package spiral_matrix

func spiralOrder(matrix [][]int) []int {
	rows, columns := len(matrix), len(matrix[0])
	if rows == 0 || columns == 0 {
		return []int{}
	}

	loOfRow, hiOfRow, loOfColumns, hiOfColumns := 0, rows-1, 0, columns-1
	result := make([]int, rows*columns)
	rankOfResult := 0
	for loOfRow <= hiOfRow && loOfColumns <= hiOfColumns {
		for i := loOfColumns; i <= hiOfColumns; i++ {
			result[rankOfResult] = matrix[loOfRow][i]
			rankOfResult++
		}
		for i := loOfRow + 1; i <= hiOfRow; i++ {
			result[rankOfResult] = matrix[i][hiOfColumns]
			rankOfResult++
		}
		if loOfRow < hiOfRow && loOfColumns < hiOfColumns {
			for i := hiOfColumns - 1; i > loOfColumns; i-- {
				result[rankOfResult] = matrix[hiOfRow][i]
				rankOfResult++
			}
			for i := hiOfRow; i > loOfRow; i-- {
				result[rankOfResult] = matrix[i][loOfColumns]
				rankOfResult++
			}
		}
		loOfRow++
		hiOfRow--
		loOfColumns++
		hiOfColumns--
	}
	return result
}
