package construct_binary_tree_from_preorder_and_inorder_traversal

// TreeNode Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	return buildChild(preorder, 0, len(preorder), inorder, 0, len(inorder))
}

func getRootOfIn(preorder []int, loPre int, hiPre int, inorder []int, loIn int, hiIn int) int {
	for i := loIn; i < hiIn; i++ {
		if inorder[i] == preorder[loPre] {
			return i
		}
	}
	return -1 // 查找失败
}

// buildChild 创建子树，assert hiPre-loPre=hiIn-loIn
func buildChild(preorder []int, loPre int, hiPre int, inorder []int, loIn int, hiIn int) *TreeNode {
	if loPre == hiPre {
		return nil
	}
	rootOfIn := getRootOfIn(preorder, loPre, hiPre, inorder, loIn, hiIn)
	return &TreeNode{
		Val:   preorder[loPre],
		Left:  buildChild(preorder, loPre+1, loPre+1+(rootOfIn-loIn), inorder, loIn, rootOfIn),
		Right: buildChild(preorder, hiPre-(hiIn-rootOfIn-1), hiPre, inorder, rootOfIn+1, hiIn),
	}
}
