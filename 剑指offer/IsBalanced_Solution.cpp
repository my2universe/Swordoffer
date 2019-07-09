
/*��׼�𰸣�������д�ģ��ع˵�ʱ��ע������һ��*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//ƽ��������Ķ��壺���������ĸ߶Ȳ����һ
/******************�������ֺõķ�������Ҫ�ظ��������**************************/
//�ظ�������Σ��ڱ�������ÿ������ʱ�򣬵��ú���TreeDepth�õ�����������������ȡ����ÿ���������������������������1��
//������һ��ƽ��Ķ����������ַ�����ȱ���ǣ������жϸ�����ǲ���ƽ��ģ���Ҫʹ��TreeDepth���������������ȣ�
//Ȼ����Ҫ�����ж������ǲ���ƽ��ģ�������Ҫʹ��TreeDepth���������������������ȣ������͵����˴������ظ�������ֻ����һ�Σ�
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) {
			return true;
		}
		int left = TreeDepth(pRoot->left);//�Ӷ��㵽�ײ�
		int right = TreeDepth(pRoot->right);
		int diff = left - right;
		if (diff > 1 || diff < -1) {
			return false;
		}
		return IsBalanced_Solution(pRoot->right) && IsBalanced_Solution(pRoot->left);
	}
private:
	int TreeDepth(TreeNode* pRoot)//�ӵײ㵽����
	{
		if (pRoot == NULL) {
			return 0;
		}
		int left = TreeDepth(pRoot->left);//������壺���������
		int right = TreeDepth(pRoot->right);//���������
		return (left > right) ? (left + 1) : (right + 1);
	}
};
/***************************ֻ����һ��******************************************/
//�ظ�������Ӱ���㷨�����ܣ����Ժ��б�Ҫ���ղ���Ҫ�ظ������ķ�������������ú�������ķ�ʽ������������ÿһ����㣬
//�ڱ�����һ�����֮ǰ���Ǿ��Ѿ���������������������ֻҪ�ڱ���ÿ������ʱ���¼������ȣ�ĳһ������ȵ�������Ҷ����·���ĳ��ȣ���
//���ǾͿ���һ�߱���һ���ж�ÿ������ǲ���ƽ��ġ�
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
private:
	int IsBalanced(TreeNode* pRoot, int* depth) {//�ӵײ㵽����
		if (pRoot == NULL) {//���������ڵ�ͱ�����Ҷ�ӽڵ���depth==0�����
			*depth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) {//�ڱ��������ڵ�֮ǰ�Ѿ��������ҽڵ��ˣ�Ȼ����ȷ����������ƽ���ǰ����������һ���ж�
			int diff = left - right;
			if (diff <= 1 && diff >= -1) {
				*depth = 1 + (left > right ? left : right);//��¼���
				return true;
			}
		}
		return false;
	}
};