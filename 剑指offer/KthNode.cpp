//中序遍历二叉搜索树
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k == 0) {
			return NULL;
		}
		return KthNodeCore(pRoot, k);
	}
private:
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k) {
		TreeNode* target = NULL;
		// 先遍历左结点
		if (pRoot->left != NULL) {
			target = KthNodeCore(pRoot->left, k);
		}
		// 如果没有找到target，则继续减小k，如果k等于1，说明到了第k大的数
		if (target == NULL) {
			if (k == 1) {
				target = pRoot;
			}
			k--;
		}
		// 如果没有找到target，继续找右结点
		if (pRoot->right != NULL && target == NULL) {
			target = KthNodeCore(pRoot->right, k);
		}
		return target;
	}
};

