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
//我写的并未通过所有的测试用例
//缺了一种情况就是全部二叉树都是相同值
//加了#也不能通过
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)//是否为对称树
	{
		if (pRoot == NULL)return true;
		vector<string>preresult = preorder(pRoot);
		vector<string>curresult = curorder(pRoot);
		for (size_t i=0;i<preresult.size();i++)
		{
			if (preresult[i] != curresult[i])return false;
		}
		return true;
	}
	vector<string>preorder(TreeNode*pRoot)
	{	
		if (pRoot != NULL)
		{
			preorder(pRoot->left);
			pre.push_back(to_string(pRoot->val));
			preorder(pRoot->right);
		}
		else
			pre.push_back("#");
		return pre;
	}
	vector<string>curorder(TreeNode*pRoot)
	{
		if (pRoot != NULL)
		{
			curorder(pRoot->right);
			cur.push_back(to_string(pRoot->val));
			curorder(pRoot->left);
		}
		else
			cur.push_back("#");
		return cur;
	}
private:
	vector<string>pre;
	vector<string>cur;
};
//考虑了我缺少的相应情况
//上边的代码不好考虑到整个二叉树都是相同值的情况
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return true;
		}
		return isSymmetriacalCor(pRoot, pRoot);
	}
private:
	bool isSymmetriacalCor(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == NULL && pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL || pRoot2 == NULL) {//同时便利，若一个空另一个不空显然是不对称的
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return isSymmetriacalCor(pRoot1->left, pRoot2->right) && isSymmetriacalCor(pRoot1->right, pRoot2->left);
	}
};