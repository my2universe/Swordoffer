////ʹ������ջ����ӡĳһ�нڵ�ʱ����һ����ӽڵ㱣�浽��Ӧ��ջ���ӡ��������ȱ������ӽڵ������ӽڵ㣬ż���㷴������ջ���Ƚ������

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

#include<vector>
using namespace std;
/***************�ٸ�����***************/
//           3
 //        6       7
//       5   8   9  11
/***********************************************����******************************************************************/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}	vector<int> v[2];//û�ζ����¶��壬������ǵ�ǰ�е�ֵ,��Ҫ���ⲿ��������ζ��û���һ��һ��Ĵ洢֮�󶼱���clear
		stack<TreeNode* > s[2];//����ջ���ֱ��������к�ż���еĽڵ�
		s[0].push(pRoot);   //�Ž�3
		while (!s[0].empty() || !s[1].empty()) {//���while���ڲ�while�Ĺ�ϵ����vector<int>��vector<vector<>>
		
			// ż����
			while (!s[0].empty()) {
				v[0].push_back(s[0].top()->val);//��ӡ�����У���ż���а�������Ҵ��ȥ��Ȼ�������нڵ㵯��
				if (s[0].top()->left != NULL) {
					s[1].push(s[0].top()->left);
				}
				if (s[0].top()->right != NULL) {
					s[1].push(s[0].top()->right);
				}
				s[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);//��ʱ�Ѿ�����ĳһ�������нڵ㣬�ʽ���Ž����ս�����
			}
			v[0].clear();
			// ������
			while (!s[1].empty()) {
				v[1].push_back(s[1].top()->val);//��ӡż���У���������Ҵ�ŵģ������Һ��󵯳�ջ7  6
				if (s[1].top()->right != NULL) {//�����а��Һ������ջ119  85
					s[0].push(s[1].top()->right);
				}
				if (s[1].top()->left != NULL) {
					s[0].push(s[1].top()->left);
				}
				s[1].pop();//��ż���нڵ㵯��
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
			v[1].clear();
		}
		return result;
	}
};
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}	
		stack<TreeNode* > s[2];//����ջ���ֱ��������к�ż���еĽڵ�
		s[0].push(pRoot);   //�Ž�3
		while (!s[0].empty() || !s[1].empty()) {//���while���ڲ�while�Ĺ�ϵ����vector<int>��vector<vector<>>
			vector<int> v[2];//û�ζ����¶��壬������ǵ�ǰ�е�ֵ,��Ҫ���ⲿ��������ζ��û���һ��һ��Ĵ洢֮�󶼱���clear������ֱ�ӷ���߾���
			// ż����
			while (!s[0].empty()) {
				v[0].push_back(s[0].top()->val);//��ӡ�����У���ż���а�������Ҵ��ȥ��Ȼ�������нڵ㵯��
				if (s[0].top()->left != NULL) {
					s[1].push(s[0].top()->left);
				}
				if (s[0].top()->right != NULL) {
					s[1].push(s[0].top()->right);
				}
				s[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);//��ʱ�Ѿ�����ĳһ�������нڵ㣬�ʽ���Ž����ս�����
			}
		
			// ������
			while (!s[1].empty()) {
				v[1].push_back(s[1].top()->val);//��ӡż���У���������Ҵ�ŵģ������Һ��󵯳�ջ7  6
				if (s[1].top()->right != NULL) {//�����а��Һ������ջ119  85
					s[0].push(s[1].top()->right);
				}
				if (s[1].top()->left != NULL) {
					s[0].push(s[1].top()->left);
				}
				s[1].pop();//��ż���нڵ㵯��
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
			
		}
		return result;
	}
};
/*******************************�Լ���д****************************************/
//д����������������stack��.  treenode��->
//�±߳������������
////class Solution {
////public:
////	vector<vector<int> > Print(TreeNode* pRoot) {
////		if (pRoot==NULL)
////		{
////			return result;
////		}
////		stack<TreeNode*>s[2];
////		s[0].push(pRoot);
////		while (!s[0].empty() || !s[1].empty())
////		{
////			vector<int>v[2];
////			while (!s[0].empty())//��ӡ�����б���ż����
////			{
////				v[0].push_back(s[0]->top()->val);
////				if (s[0]->top().left!=NULL)
////				{
////					s[1]->push(s[0].top().left);
////				}
////				if (s[0].top()->right!=NULL)
////				{
////					s[1].push(s[0].top->right);
////				}
////				s[0]->pop();
////			}
////			if (!v[0].empty())
////			{
////				result.push_back(v[0]);
////			}
////			while (!s[1]empty())//��ӡ�����б���ż����
////			{
////				v[1].push_back(s[1]->top().val);
////				if (s[1]->top().left != NULL)
////				{
////					s[0]->push(s[1]->top.right);
////				}
////				if (s[1]->top().right != NULL)
////				{
////					s[0]->push(s[1]->top().left);
////				}
////			}
////			if (!v[1].empty())
////			{
////				result.push_back(v[1]);
////			}
////			s[1]->pop();
////		}
////		return result;
////	}
////private:
////	vector<vector<int>>result;
////};