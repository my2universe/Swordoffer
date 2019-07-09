//找到环的入口

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	int Findcount(ListNode* pHead)
	{
		//环的长度为count
		ListNode*pFast = pHead;
		ListNode*pSlow = pHead;
		int count = 1;
		//这里需要注意必须判定pfast和pslow是否为空
		//此时外循环的pfast判断的是pfast->next->next是否为空
		//里边的if判断的是pfast->next是否为空
		//为了省去循环外边的pslow和pfast判定为空则输出null
		//把它放到循环里边来
		while (pFast!=NULL&&pSlow!=NULL)
		{		
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != NULL)pFast = pFast->next;
			if (pSlow == NULL || pFast == NULL)return NULL;
			if (pFast==pSlow)break;
			
		}
		ListNode*pNode = pSlow->next;
		while (pNode!=pSlow)
		{
			count++;
			pNode = pNode->next;
		}
		return count;
	}
	//已知环的长度n，设定一个指针先走长度n，然后统领一个指针一起向后遍历，最终重合的位置必为环的入口
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead==NULL)
		{
			return NULL;
		}
		if (pHead->next==NULL)
		{
			return NULL;
		}
		ListNode*p1 = pHead;
		ListNode*p2 = pHead;
		int count = Findcount(pHead);
		while (count--)
		{
			p2 = p2->next;
		}
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};	