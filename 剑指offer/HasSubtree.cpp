//输入两棵树，判断b是不是a的子结构
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//思路：先找到树A中和树B根节点一样的节点，在判断以r为节点的子树是不是包含b一样的结构
//涉及到遍历树的基本知识，这里使用递归
//具体流程就是先（前中后序遍历二叉树找到根节点，没找到返回false，然后在找到的节点位置递归遍历子树判断是否与b树结构相同）
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) {
			if (pRoot1->val == pRoot2->val) {
				//先序遍历
				result = DoesTree1HasTree2(pRoot1, pRoot2);// 此函数功能为寻找树A中和树B根节点一样的节点，找到后判断是否包含字数
			}
			if (!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
	//根节点
	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};