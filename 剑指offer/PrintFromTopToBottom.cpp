//ʹ�ö��д�ӡ������
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


//˼·���Ӹ��ڵ㿪ʼ�������ҽڵ㣬Ȼ�����ҽڵ�ŵ�������ߣ�ȡ����ͷ���ٱ������е����ҽڵ㣬������У�Ȼ��ȡ����ͷѭ����ֱ��null


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
			if (pTemp->left!=NULL)//����ע�ⲻ���ø��ڵ����ѭ��������дһ���ݹ�����ԣ��ݹ�Ӧ�ò���
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
