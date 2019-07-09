//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径，
//路径定义为从树的根节点开始一直到叶节点所经过的节点
//还要求了数组长度大的数组靠前
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//每次遍历，我们先把root的值压入tmp，然后判断当前root是否同时满足：
//与给定数值相减为0；
//左子树为空；
//右子树为空。
//如果满足条件，就将tmp压入result中，否则，依次遍历左右子树。需要注意的是，
//遍历左右子树的时候，全局变量tmp是不清空的，直到到了根结点才请空tmp。
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
	{
		//其实这里返回result没有意义，因为result为全局变量，全程记录结果，这里return应该只是为了有一个合理的退出
		if (root==NULL)//意味着到了叶子节点依然不满足形成路径的条件，就把当前的result的结果记录下来并继续去遍历父结点或者右子节点
		{
			return result;
		}
		tmp.push_back(root->val);
		if (expectNumber-(root->val) == 0 && root->left == NULL && root->right == NULL)
		{
			result.push_back(tmp);
		}
		FindPath(root->left, expectNumber - (root->val));
		FindPath(root->right, expectNumber - (root->val));
	}
private:
	vector<vector<int>>result;
	vector<int>tmp;
};