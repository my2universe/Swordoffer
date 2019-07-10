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
//��д�Ĳ�δͨ�����еĲ�������
//ȱ��һ���������ȫ��������������ֵͬ
//����#Ҳ����ͨ��
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)//�Ƿ�Ϊ�Գ���
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
//��������ȱ�ٵ���Ӧ���
//�ϱߵĴ��벻�ÿ��ǵ�����������������ֵͬ�����
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
		if (pRoot1 == NULL || pRoot2 == NULL) {//ͬʱ��������һ������һ��������Ȼ�ǲ��ԳƵ�
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return isSymmetriacalCor(pRoot1->left, pRoot2->right) && isSymmetriacalCor(pRoot1->right, pRoot2->left);
	}
};