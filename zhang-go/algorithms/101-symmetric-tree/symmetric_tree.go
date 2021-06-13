package symmetric_tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if root.Left == nil && root.Right != nil || root.Left != nil && root.Right == nil {
		return false
	}
	nodeQueue := []*TreeNode{root.Left, root.Right}
	for len(nodeQueue) > 0 {
		node1, node2 := nodeQueue[0], nodeQueue[1]
		nodeQueue = nodeQueue[2:]
		if node1 == nil && node2 == nil {
			continue
		}
		if node1 == nil || node2 == nil {
			return false
		}
		if node1.Val != node2.Val {
			return false
		}
		nodeQueue = append(nodeQueue, node1.Left, node2.Right, node1.Right, node2.Left)
	}
	return true
}
