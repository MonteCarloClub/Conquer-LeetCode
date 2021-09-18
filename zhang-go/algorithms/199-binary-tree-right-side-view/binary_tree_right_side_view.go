package binary_tree_right_side_view

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	var (
		treeNodeQueue []*TreeNode
		result        []int
	)
	if root == nil {
		return result
	}
	treeNodeQueue = append(treeNodeQueue, root)
	for len(treeNodeQueue) > 0 {
		lenOfThisHeight := len(treeNodeQueue)
		var newTreeNodeQueue []*TreeNode
		for i := 0; i < lenOfThisHeight; i++ {
			if treeNodeQueue[i].Left != nil {
				newTreeNodeQueue = append(newTreeNodeQueue, treeNodeQueue[i].Left)
			}
			if treeNodeQueue[i].Right != nil {
				newTreeNodeQueue = append(newTreeNodeQueue, treeNodeQueue[i].Right)
			}
			if i == lenOfThisHeight-1 {
				result = append(result, treeNodeQueue[i].Val)
			}
		}
		treeNodeQueue = newTreeNodeQueue
	}
	return result
}
