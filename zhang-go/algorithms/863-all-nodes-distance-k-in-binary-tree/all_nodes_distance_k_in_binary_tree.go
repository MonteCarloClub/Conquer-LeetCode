package all_nodes_distance_k_in_binary_tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var (
	parentMap   map[int]*TreeNode
	result      []int
	targetDepth int
)

func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	parentMap = make(map[int]*TreeNode)
	result = make([]int, 0)
	targetDepth = k

	findParent(root)

	findResult(target, nil, 0)
	return result
}

func findParent(treeNode *TreeNode) {
	if treeNode.Left != nil {
		parentMap[treeNode.Left.Val] = treeNode
		findParent(treeNode.Left)
	}
	if treeNode.Right != nil {
		parentMap[treeNode.Right.Val] = treeNode
		findParent(treeNode.Right)
	}
}

func findResult(treeNode, from *TreeNode, depth int) {
	if treeNode == nil {
		return
	}

	if depth == targetDepth {
		result = append(result, treeNode.Val)
		return
	}

	if treeNode.Left != from {
		findResult(treeNode.Left, treeNode, depth+1)
	}
	if treeNode.Right != from {
		findResult(treeNode.Right, treeNode, depth+1)
	}
	if parentMap[treeNode.Val] != from {
		findResult(parentMap[treeNode.Val], treeNode, depth+1)
	}
}
