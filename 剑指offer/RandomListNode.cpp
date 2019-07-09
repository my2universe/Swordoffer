
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
//1.复制链表2.处理random3.拆分复杂指针
class Solution {
public:
	//复制链表
	void CloneNodes(RandomListNode* pHead) 
	{
		RandomListNode*p1 = pHead;
		while (p1 != NULL)
		{
			RandomListNode* pCloned = new RandomListNode(0);
			pCloned->next = p1->next;
			pCloned->label = p1->label;
			pCloned->random = NULL;

			p1->next = pCloned;
			p1 = pCloned->next;
		}
	}
	//第二步，处理复杂指针的random
	void ConnectSiblingNodes(RandomListNode* pHead)
	{
		RandomListNode*p1 = pHead;
		//因为p1后边不可能是null，所以直接判断p1！=null即可
		while (p1 != NULL)
		{
			RandomListNode*pCloned = p1->next;
			//这里是要复制p1->random;
			if (p1->random != NULL)
			{
				pCloned->random = p1->random->next;
			}
			p1 = pCloned->next;
		}
	}
	//第三步，拆分复杂指针
	RandomListNode* ReconnectNodes(RandomListNode* pHead) 
	{
		RandomListNode*p1 = pHead;
		RandomListNode*pHead2 = NULL;
		RandomListNode*p2 = NULL;
		//把头结点拿出来
		if (p1 != NULL) {
			pHead2 = p2 = p1->next;
			p1->next = p2->next;
			p1 = p1->next;
		}
		while (p1 != NULL)
		{
			p2->next = p1->next;
			p2 = p2->next;
			p1->next = p2->next;
			p1 = p1->next;
		}
		return pHead2;
	}
	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}
};