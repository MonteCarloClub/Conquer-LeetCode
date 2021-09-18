package sum_root_to_leaf_numbers

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(root *TreeNode, predSumNumbers int) int {
	if root == nil {
		return 0
	}
	sum := predSumNumbers*10 + root.Val
	if root.Left == nil && root.Right == nil {
		return sum
	}
	return dfs(root.Left, sum) + dfs(root.Right, sum)
}

func sumNumbers(root *TreeNode) int {
	return dfs(root, 0)
}
