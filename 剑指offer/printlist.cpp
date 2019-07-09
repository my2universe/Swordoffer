#include<vector>
using namespace std;
struct ListNode {
	int val;
    struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//链表倒序输出
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int>res;
		vector<int>result;
		ListNode*p = head;
		for (;p!=NULL;p=p->next)
		{
			res.push(p->val);
		}
		while (!res.empty())
		{
			result.push_back(res.top());
			res.pop();
		}
		return result;

	}
};
//输出链表倒数第k节点 
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode*p1 = pListHead;
		ListNode*p2 = pListHead;
		if (pListHead == NULL||k==0)return;
		for (int i=0;i<k-1;i++)
		{
			if (p2->next != NULL)
				p2 = p2->next;
			else
				return NULL;
		}
		while (p2->next != NULL)
		{
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1;

	}
};