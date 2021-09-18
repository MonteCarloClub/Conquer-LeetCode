package path_sum_ii

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, targetSum int) [][]int {
	if root == nil {
		return nil
	}
	if root.Left == nil && root.Right == nil {
		if root.Val == targetSum {
			return [][]int{{root.Val}}
		}
		return nil
	}
	var results [][]int
	if root.Left != nil {
		resultsOfLeft := pathSum(root.Left, targetSum-root.Val)
		for _, resultOfLeft := range resultsOfLeft {
			results = append(results, append([]int{root.Val}, resultOfLeft...))
		}
	}
	if root.Right != nil {
		resultsOfRight := pathSum(root.Right, targetSum-root.Val)
		for _, resultOfRight := range resultsOfRight {
			results = append(results, append([]int{root.Val}, resultOfRight...))
		}
	}
	return results
}
