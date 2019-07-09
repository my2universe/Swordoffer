
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode*p1 = pHead1;
		ListNode*p2 = pHead2;
		ListNode*pHead3 = NULL;
		if (pHead1 == NULL)return pHead2;
		if (pHead2 == NULL)return pHead1;
		if (pHead1->val < pHead2->val)
		{
			pHead3 = p1;
			p1 = p1->next;
		}
		else if (pHead1->val >= pHead2->val)
		{
			pHead3 = p2;
			p2 = p2->next;
		}
		ListNode*p3 = pHead3;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val < p2->val)
			{
				p3->next = p1;
				p1 = p1->next;
			}
			else
			{
				p3->next = p2;
				p2 = p2->next;
			}
			p3 = p3->next;
		}
		if (p1 != NULL)p3->next = p1;
		if (p2 != NULL)p3->next = p2;
		return pHead3;
	}
};