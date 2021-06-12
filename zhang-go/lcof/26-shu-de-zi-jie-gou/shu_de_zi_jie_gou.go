package shu_de_zi_jie_gou

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubStructure(A *TreeNode, B *TreeNode) bool {
	if A == nil || B == nil {
		return false
	}
	if A.Val == B.Val && isEqual(A.Left, B.Left) && isEqual(A.Right, B.Right) {
		return true
	}
	return isSubStructure(A.Left, B) || isSubStructure(A.Right, B)
}

func isEqual(A *TreeNode, B *TreeNode) bool {
	if B == nil {
		return true
	}
	// A == nil && B != nil
	if A == nil {
		return false
	}
	// A != nil && B != nil
	if A.Val == B.Val {
		return isEqual(A.Left, B.Left) && isEqual(A.Right, B.Right)
	}
	return false
}
