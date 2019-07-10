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
		if (pNode == NULL)
		{
			return NULL;
		}
		if (pNode->right != NULL)
		{
			TreeLinkNode*pNext = pNode->right;
			while (pNext->left != NULL)
			{
				pNext = pNext->left;
			}
			return pNext;
		}
		else if (pNode->next != NULL)
		{
			TreeLinkNode*pFa = pNode->next;
			if (pFa->left == pNode)
				return pFa;
			else if (pFa->right == pNode)
			{
				while (pFa->next != NULL)
				{
					TreeLinkNode*pWrite = pFa->next;
					if (pFa == pWrite->left)
					{
						return pFa;
					}
					else
						pFa = pFa->next;
				}
				return pFa;
			}
		}
	}
};
//class Solution {
//public:
//	TreeLinkNode* GetNext(TreeLinkNode* pNode)
//	{
//		if (pNode == NULL) {
//			return NULL;
//		}
//		TreeLinkNode* pNext = NULL;
//		// ��ǰ���������������ô������һ�������������������������ӽ��
//		if (pNode->right != NULL) {
//			TreeLinkNode* pRight = pNode->right;
//			while (pRight->left != NULL) {
//				pRight = pRight->left;
//			}
//			pNext = pRight;
//		}
//		// ��ǰ�����������������Ҫ�ҵ�һ���������������������Ľ��
//		else if (pNode->next != NULL) {
//			// ��ǰ���
//			TreeLinkNode* pCur = pNode;
//			// ���ڵ�
//			TreeLinkNode* pPar = pNode->next;
//			while (pPar != NULL && pCur == pPar->right) {
//				pCur = pPar;
//				pPar = pCur->next;
//			}
//			pNext = pPar;
//		}
//		return pNext;
//	}
//};