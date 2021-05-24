/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) int {
    if root == nil {
        return 0
    }
    v := root.Val
    res := 0
    if v>=low&&v<=high {
        res+=v
        res+=rangeSumBST(root.Left, low, high);
        res+=rangeSumBST(root.Right, low, high);
    } else if v<low {
        res+=rangeSumBST(root.Right, low, high);
    } else if v>high {
        res+=rangeSumBST(root.Left, low, high);
    }
    return res
}
