package binary_tree_zigzag_level_order_traversal

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) (ans [][]int) {
	if root == nil {
		return nil
	}
	layerArray := []*TreeNode{root}
	countOfLayer := 1
	for len(layerArray) > 0 {
		nextLayerArray := []*TreeNode{}
		ansOfLayer := []int{}
		for i := 0; i < len(layerArray); i++ {
			if layerArray[i].Left != nil {
				nextLayerArray = append(nextLayerArray, layerArray[i].Left)
			}
			if layerArray[i].Right != nil {
				nextLayerArray = append(nextLayerArray, layerArray[i].Right)
			}
		}

		if countOfLayer%2 == 0 {
			for i := len(layerArray) - 1; i >= 0; i-- {
				ansOfLayer = append(ansOfLayer, layerArray[i].Val)
			}
		} else {
			for i := 0; i < len(layerArray); i++ {
				ansOfLayer = append(ansOfLayer, layerArray[i].Val)
			}
		}

		layerArray = nextLayerArray
		ans = append(ans, ansOfLayer)
		countOfLayer++
	}
	return
}
