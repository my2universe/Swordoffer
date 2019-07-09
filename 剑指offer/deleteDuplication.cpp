
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//置一个pre保存不与当前值重复的前一个值
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead==NULL)
		{
			return NULL;
		}
		ListNode*pNode = pHead;
		ListNode*pre = pHead;
		while (pNode->next!=NULL)
		{
			if (pNode->val == pre->val)//如果当前节点和pre相同则意味着重复，不断往后遍历pnode即可
			{
				pNode = pNode->next;
			}
			else//如果当前节点不同于pre，则需要更新pre和pnode
			{
				if(pNode!=NULL)pre->next = pNode;
				pre = pre->next;
				pNode = pNode->next;
			}	
		}
		return pHead;
	}
};
//上边理解错了题意以为是要剔除重复节点


//下边为此题解答，只要重复就提出122334->14
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL) {
			return NULL;
		}
		// 指向当前结点前最晚访问过的不重复结点
		ListNode* pPre = NULL;
		// 指向当前处理的结点
		ListNode* pCur = pHead;
		// 指向当前结点后面的结点
		ListNode* pNext = NULL;

		while (pCur != NULL) {
			// 如果当前结点与下一个结点相同
			if (pCur->next != NULL && pCur->val == pCur->next->val) {
				pNext = pCur->next;
				// 找到不重复的最后一个结点位置
				while (pNext->next != NULL && pNext->next->val == pCur->val) {
					pNext = pNext->next;
				}
				// 如果pCur指向链表中第一个元素，pCur -> ... -> pNext ->... 
				// 要删除pCur到pNext, 将指向链表第一个元素的指针pHead指向pNext->next。
				if (pCur == pHead) {
					pHead = pNext->next;
				}
				// 如果pCur不指向链表中第一个元素，pPre -> pCur ->...->pNext ->... 
				// 要删除pCur到pNext，即pPre->next = pNext->next
				else {
					pPre->next = pNext->next;
				}
				// 向前移动
				pCur = pNext->next;
			}
			// 如果当前结点与下一个结点不相同
			else {
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};