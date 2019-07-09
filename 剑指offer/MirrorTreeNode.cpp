//很简单，举例来讲就是根节点的左右节点交换顺序递归

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL))//这里缺了对根节点的判定，如果根节点为空直接返回即可
		{
			return;
		}
		TreeNode*pTemp = pRoot->left;//左右节点进行交换
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;
		if (pRoot->left)//这里记得对左右节点进行判定，存在并非完全二叉树的情况
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
	}
};