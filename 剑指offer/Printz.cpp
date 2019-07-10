////使用两个栈，打印某一行节点时把下一层的子节点保存到相应的栈里，打印奇数层就先保存左子节点再右子节点，偶数层反过来（栈的先进后出）

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
/***************举个例子***************/
//           3
 //        6       7
//       5   8   9  11
/***********************************************看答案******************************************************************/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}	vector<int> v[2];//没次都重新定义，保存的是当前行的值,若要在外部定义则意味着没完成一次一层的存储之后都必须clear
		stack<TreeNode* > s[2];//两个栈，分别存放奇数行和偶数行的节点
		s[0].push(pRoot);   //放进3
		while (!s[0].empty() || !s[1].empty()) {//外层while和内层while的关系就像vector<int>和vector<vector<>>
		
			// 偶数行
			while (!s[0].empty()) {
				v[0].push_back(s[0].top()->val);//打印奇数行，将偶数行按先左后右存进去，然后将奇数行节点弹出
				if (s[0].top()->left != NULL) {
					s[1].push(s[0].top()->left);
				}
				if (s[0].top()->right != NULL) {
					s[1].push(s[0].top()->right);
				}
				s[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);//此时已经放入某一行奇数行节点，故将其放进最终结果里边
			}
			v[0].clear();
			// 奇数行
			while (!s[1].empty()) {
				v[1].push_back(s[1].top()->val);//打印偶数行（按先左后右存放的）按先右后左弹出栈7  6
				if (s[1].top()->right != NULL) {//奇数行按右后左存入栈119  85
					s[0].push(s[1].top()->right);
				}
				if (s[1].top()->left != NULL) {
					s[0].push(s[1].top()->left);
				}
				s[1].pop();//将偶数行节点弹出
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
		stack<TreeNode* > s[2];//两个栈，分别存放奇数行和偶数行的节点
		s[0].push(pRoot);   //放进3
		while (!s[0].empty() || !s[1].empty()) {//外层while和内层while的关系就像vector<int>和vector<vector<>>
			vector<int> v[2];//没次都重新定义，保存的是当前行的值,若要在外部定义则意味着没完成一次一层的存储之后都必须clear，所以直接放里边就行
			// 偶数行
			while (!s[0].empty()) {
				v[0].push_back(s[0].top()->val);//打印奇数行，将偶数行按先左后右存进去，然后将奇数行节点弹出
				if (s[0].top()->left != NULL) {
					s[1].push(s[0].top()->left);
				}
				if (s[0].top()->right != NULL) {
					s[1].push(s[0].top()->right);
				}
				s[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);//此时已经放入某一行奇数行节点，故将其放进最终结果里边
			}
		
			// 奇数行
			while (!s[1].empty()) {
				v[1].push_back(s[1].top()->val);//打印偶数行（按先左后右存放的）按先右后左弹出栈7  6
				if (s[1].top()->right != NULL) {//奇数行按右后左存入栈119  85
					s[0].push(s[1].top()->right);
				}
				if (s[1].top()->left != NULL) {
					s[0].push(s[1].top()->left);
				}
				s[1].pop();//将偶数行节点弹出
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
			
		}
		return result;
	}
};
/*******************************自己复写****************************************/
//写的这段最大的问题就是stack用.  treenode用->
//下边程序是有问题的
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
////			while (!s[0].empty())//打印奇数行保存偶数行
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
////			while (!s[1]empty())//打印奇数行保存偶数行
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