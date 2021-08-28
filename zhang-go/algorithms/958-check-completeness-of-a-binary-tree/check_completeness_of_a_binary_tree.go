package check_completeness_of_a_binary_tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isCompleteTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	parents := []*TreeNode{root}
	status := getStatusOfTree(parents)
	for status == 0 {
		parents = getChildren(parents)
		status = getStatusOfTree(parents)
	}
	return status == 1
}

func getChildren(parents []*TreeNode) []*TreeNode {
	chilren := []*TreeNode{}
	for _, parent := range parents {
		chilren = append(chilren, parent.Left)
		chilren = append(chilren, parent.Right)
	}
	return chilren
}

func getStatusOfTree(nodes []*TreeNode) int {
	if nodes[0] == nil {
		for _, node := range nodes {
			if node != nil {
				return -1
			}
		}
		return 1
	}

	rankOfNil := 0
	for i, node := range nodes {
		if node == nil && rankOfNil == 0 {
			rankOfNil = i
		}
		if node != nil && rankOfNil > 0 {
			return -1
		}
	}
	if rankOfNil == 0 {
		return 0
	}
	for i := 0; i < rankOfNil; i++ {
		if nodes[i].Left != nil || nodes[i].Right != nil {
			return -1
		}
	}
	return 1
}
