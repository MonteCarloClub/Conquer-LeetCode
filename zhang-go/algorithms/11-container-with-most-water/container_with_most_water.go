package container_with_most_water

func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}

func maxArea(height []int) int {
	if len(height) == 0 {
		return 0
	}
	lo, hi := 0, len(height)-1
	result := 0
	for lo < hi {
		area := min(height[lo], height[hi]) * (hi - lo)
		if area > result {
			result = area
		}
		if height[lo] < height[hi] {
			lo++
		} else {
			hi--
		}
	}
	return result
}
