package word_search

func exist(board [][]byte, word string) bool {
	xMax := len(board)
	yMax := len(board[0])

	for x := 0; x < xMax; x++ {
		for y := 0; y < yMax; y++ {
			visited := make([][]bool, xMax)
			for i := 0; i < xMax; i++ {
				visited[i] = make([]bool, yMax)
			}
			if suffixExist(board, word, x, y, xMax, yMax, visited) {
				return true
			}
		}
	}
	return false
}

func suffixExist(board [][]byte, suffixWord string, x int, y int, xMax int, yMax int, visited [][]bool) bool {
	if len(suffixWord) == 1 && suffixWord[0] == board[x][y] && !visited[x][y] {
		return true
	}

	if suffixWord[0] == board[x][y] {
		newVisited := visited
		newVisited[x][y] = true

		if inTheInterval(x-1, 0, xMax) && !visited[x-1][y] {
			if suffixExist(board, suffixWord[1:], x-1, y, xMax, yMax, newVisited) {
				return true
			}
		}
		if inTheInterval(x+1, 0, xMax) && !visited[x+1][y] {
			if suffixExist(board, suffixWord[1:], x+1, y, xMax, yMax, newVisited) {
				return true
			}
		}
		if inTheInterval(y-1, 0, yMax) && !visited[x][y-1] {
			if suffixExist(board, suffixWord[1:], x, y-1, xMax, yMax, newVisited) {
				return true
			}
		}
		if inTheInterval(y+1, 0, yMax) && !visited[x][y+1] {
			if suffixExist(board, suffixWord[1:], x, y+1, xMax, yMax, newVisited) {
				return true
			}
		}
		newVisited[x][y] = false
	}
	return false
}

func inTheInterval(w int, wMin int, wMax int) bool {
	return w >= wMin && w < wMax
}
