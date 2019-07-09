
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int pHead1length = Getlistlength(pHead1);
		int pHead2length = Getlistlength(pHead2);
		int lengthcha = pHead1length - pHead2length;
		
		int i = abs(lengthcha);
		if (lengthcha < 0)
		{
			while (pHead2!=NULL&&i!=0)
			{
				pHead2 = pHead2->next;
				i--;
			}
		}
		else if (lengthcha > 0)
		{
			while (pHead1 != NULL && i != 0)
			{
				pHead1 = pHead1->next;
				i--;
			}
		}
		while (pHead1!=NULL&&pHead2!=NULL)
		{
			if (pHead1==pHead2)break;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return pHead1;
	}
	int Getlistlength(ListNode*pNode)
	{
		int length = 0;
		while (pNode != NULL)
		{
			length++;
			pNode = pNode->next;
		}
		return length;
	}
};