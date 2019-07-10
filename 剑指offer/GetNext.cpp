//给定一个二叉树和其中一个节点，找出中顺=序遍历的下一个节点并返回
//书中节点不仅包含左右子系欸但，同时包含指向父节点的指针
//首先要分析清楚各种情况
//1.某节点有右子树，则其下一个节点为右子树的最左子节点
//2.若无右子树，且该节点为上一个节点的左节点，则下一个节点为其父节点
//3.若无右子树，而且是其父节点的右节点，则需要向上遍历直到找到一个节点是其父节点的左子节点

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
//		// 当前结点有右子树，那么它的下一个结点就是它的右子树中最左子结点
//		if (pNode->right != NULL) {
//			TreeLinkNode* pRight = pNode->right;
//			while (pRight->left != NULL) {
//				pRight = pRight->left;
//			}
//			pNext = pRight;
//		}
//		// 当前结点无右子树，则需要找到一个是它父结点的左子树结点的结点
//		else if (pNode->next != NULL) {
//			// 当前结点
//			TreeLinkNode* pCur = pNode;
//			// 父节点
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