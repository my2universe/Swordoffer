//�ܼ򵥣������������Ǹ��ڵ�����ҽڵ㽻��˳��ݹ�

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
	void Mirror(TreeNode *pRoot) {
		if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL))//����ȱ�˶Ը��ڵ���ж���������ڵ�Ϊ��ֱ�ӷ��ؼ���
		{
			return;
		}
		TreeNode*pTemp = pRoot->left;//���ҽڵ���н���
		pRoot->left = pRoot->right;
		pRoot->right = pTemp;
		if (pRoot->left)//����ǵö����ҽڵ�����ж������ڲ�����ȫ�����������
			Mirror(pRoot->left);
		if (pRoot->right)
			Mirror(pRoot->right);
	}
};