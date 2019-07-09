//输入二叉树前序遍历和中序遍历的结果或者重建的二叉树
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0) 
		{                    //如果为空，返回NULL
			return NULL;
		}
		int root = 0;
		//依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
		vector<int> left_pre, right_pre, left_vin, right_vin;
		//中序遍历第一个节点一定为根节点
		TreeNode* head = new TreeNode(pre[0]);
		for (int i = 0; i < vin.size(); i++)
		{
			if (pre[0] == vin[i])
			{
				root = i;
				break;
			}
		}
		for (int i = 0; i < root; i++)
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);
		}
		for (int i = root+1; i <vin.size(); i++)//注意root+1
		{
			right_vin.push_back(vin[i]);//注意里边都是i
			right_pre.push_back(pre[i]);
		}
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;

	}
};