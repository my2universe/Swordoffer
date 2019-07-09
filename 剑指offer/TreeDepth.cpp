//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点
//（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
//两种方法深度优先和广度优先都得掌握


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/**********************************深度优先DFS********************************************/
//思路：利用递归拆分例如根节点深度为1，那么这棵树必然是他的子树的深度加一，如果不存在右子树就是左子树深度加以，
//若不存在左子树就是右子树深度加一，若左右子树都存在，那么就比较左右子树的深度然后再加一
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
		//第一次递归的时候对根节点分出了左右子树，然后先进入左子树，等左子树递归完再进入右子树进行递归
	{
		if (pRoot == NULL) {
			return 0;
		}
		int left = TreeDepth(pRoot->left);//获得左子树的深度
		int right = TreeDepth(pRoot->right);//货的右子树的深度
		return (left > right) ? (left + 1) : (right + 1);
	}
};
/***************************************广度优先搜索****************************************/
//用了队列
//其实这个过程就是按层将每一层的节点放到队列里边，
//然后再取出来本层的将下一层放进去，depth不断加一，最终获得整棵树的深度
//这里突然考虑到了迭代和递归地区别
//迭代是循环
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return 0;
		}
		queue<TreeNode*	> que;
		int depth = 0;
		que.push(pRoot);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) { 
				TreeNode* node = que.front();
				que.pop();
				if (node->left) {
					que.push(node->left);
				}
				if (node->right) {
					que.push(node->right);
				}
			}
		}
		return depth;
	}
};