//����һ��������������һ���ڵ㣬�ҳ���˳=���������һ���ڵ㲢����
//���нڵ㲻������������ϵ�G����ͬʱ����ָ�򸸽ڵ��ָ��
//����Ҫ��������������
//1.ĳ�ڵ�����������������һ���ڵ�Ϊ�������������ӽڵ�
//2.�������������Ҹýڵ�Ϊ��һ���ڵ����ڵ㣬����һ���ڵ�Ϊ�丸�ڵ�
//3.�������������������丸�ڵ���ҽڵ㣬����Ҫ���ϱ���ֱ���ҵ�һ���ڵ����丸�ڵ�����ӽڵ�

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{

	}
};