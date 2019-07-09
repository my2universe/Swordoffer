
/*标准答案，不是我写的，回顾的时候注意重现一下*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//平衡二叉树的定义：左右子树的高度差不超过一
/******************费力不讨好的方法，需要重复遍历多次**************************/
//重复遍历多次：在遍历树的每个结点的时候，调用函数TreeDepth得到它的左右子树的深度。如果每个结点的左右子树的深度相差都不超过1，
//则这是一颗平衡的二叉树。这种方法的缺点是，首先判断根结点是不是平衡的，需要使用TreeDepth获得左右子树的深度，
//然后还需要继续判断子树是不是平衡的，还是需要使用TreeDepth获得子树的左右子树的深度，这样就导致了大量的重复遍历。只遍历一次：
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) {
			return true;
		}
		int left = TreeDepth(pRoot->left);//从顶层到底层
		int right = TreeDepth(pRoot->right);
		int diff = left - right;
		if (diff > 1 || diff < -1) {
			return false;
		}
		return IsBalanced_Solution(pRoot->right) && IsBalanced_Solution(pRoot->left);
	}
private:
	int TreeDepth(TreeNode* pRoot)//从底层到顶层
	{
		if (pRoot == NULL) {
			return 0;
		}
		int left = TreeDepth(pRoot->left);//宏观意义：左子树深度
		int right = TreeDepth(pRoot->right);//右子树深度
		return (left > right) ? (left + 1) : (right + 1);
	}
};
/***************************只遍历一次******************************************/
//重复遍历会影响算法的性能，所以很有必要掌握不需要重复遍历的方法。如果我们用后序遍历的方式遍历二叉树的每一个结点，
//在遍历到一个结点之前我们就已经遍历了它的左右子树。只要在遍历每个结点的时候记录它的深度（某一结点的深度等于它到叶结点的路径的长度），
//我们就可以一边遍历一边判断每个结点是不是平衡的。
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
private:
	int IsBalanced(TreeNode* pRoot, int* depth) {//从底层到顶层
		if (pRoot == NULL) {//遍历到根节点和遍历到叶子节点是depth==0的情况
			*depth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) {//在遍历到根节点之前已经遍历左右节点了，然后在确保左右子树平衡的前提下再像上一层判断
			int diff = left - right;
			if (diff <= 1 && diff >= -1) {
				*depth = 1 + (left > right ? left : right);//记录深度
				return true;
			}
		}
		return false;
	}
};