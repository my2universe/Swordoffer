//使用队列打印二叉树
#include <vector>
using namespace std;
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		TreeNode* fr;
		if (root == NULL) {
			return result;
		}
		que.push(root);
		while (!que.empty()) {
			fr = que.front();
			result.push_back(fr->val);
			if (fr->left != NULL) {
				que.push(fr->left);
			}
			if (fr->right != NULL) {
				que.push(fr->right);
			}
			que.pop();
		}
		return result;
	}
private:
	vector<int> result;
	queue<TreeNode*> que;
};


//思路：从根节点开始遍历左右节点，然后将左右节点放到队列里边，取出队头，再遍历队列的左右节点，加入队列，然后取出队头循环，直至null


class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (root==NULL)
		{
			return result;
		}
		TreeNode*pTemp;
		que.push(root);
		while (!que.empty())
		{
			pTemp = que.front();
			result.push_back(pTemp->val);
			if (pTemp->left!=NULL)//这里注意不是用根节点进行循环（可有写一个递归的试试）递归应该不行
			{
				que.push(pTemp->left);
			}
			if (pTemp->right!=NULL)
			{
				que.push(pTemp->left);
			}
			que.pop();
		}
		return result;
	}
private:
	vector<int> result;
	queue<TreeNode*> que;
};
