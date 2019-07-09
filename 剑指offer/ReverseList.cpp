//反转链表

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)return pHead;
		ListNode*p = pHead;
		ListNode*pNode = NULL;
		while (p!=NULL)//由于p实际上指的是马上要从原链表上拆下来的节点，即意味着是原链表的节点，而原链表遍历到末尾才会为空
		{
			ListNode *tmp = p->next;//记录断开的节点
			p->next = pNode;//将原链表前边的节点放到当前节点的后边
			pNode = p;//然后更新原链表当前节点的前一个节点
			p = tmp;//再将断开的节点赋给p作为当前节点
		}
		return pNode;

	}
};