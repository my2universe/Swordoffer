
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
////用栈是不能达到这样顺序输出的夏国的，只能用队列
//class Solution {
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//		vector<vector<int>>result;
//		stack<TreeNode*>s[2];//两个栈一层一层存
//		s[0].push(pRoot);
//		if (pRoot == NULL) {
//			return result;
//		}
//		while (!s[0].empty() || !s[1].empty())
//		{
//			vector<int>v[2];
//			while (!s[0].empty())
//			{
//				v[0].push_back(s[0].top()->val);
//				if (s[0].top()->right != NULL)
//				{
//					s[1].push(s[0].top()->right);
//				}
//				if (s[0].top()->left != NULL)
//				{
//					s[1].push(s[0].top()->left);
//				}
//				s[0].pop();
//			}
//			if (!v[0].empty())
//			{
//				result.push_back(v[0]);
//			}
//			while (!s[1].empty())
//			{
//				v[1].push_back(s[1].top()->val);
//				if (s[1].top()->right != NULL)
//				{
//					s[0].push(s[1].top()->right);
//				}
//				if (s[1].top()->left != NULL)
//				{
//					s[0].push(s[1].top()->left);
//				}
//				s[1].pop();
//			}
//			if (!v[1].empty())
//			{
//				result.push_back(v[1]);
//			}
//		}
//		return result;
//	}
//
//};
//用队列
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > result;
		if (pRoot == NULL) {
			return result;
		}
		queue<TreeNode* > nodes[2];
		nodes[0].push(pRoot);
		while (!nodes[0].empty() || !nodes[1].empty()) {
			vector<int> v[2];
			while (!nodes[0].empty()) {
				v[0].push_back(nodes[0].front()->val);
				if (nodes[0].front()->left != NULL) {
					nodes[1].push(nodes[0].front()->left);
				}
				if (nodes[0].front()->right != NULL) {
					nodes[1].push(nodes[0].front()->right);
				}
				nodes[0].pop();
			}
			if (!v[0].empty()) {
				result.push_back(v[0]);
			}
			while (!nodes[1].empty()) {
				v[1].push_back(nodes[1].front()->val);
				if (nodes[1].front()->left != NULL) {
					nodes[0].push(nodes[1].front()->left);
				}
				if (nodes[1].front()->right != NULL) {
					nodes[0].push(nodes[1].front()->right);
				}
				nodes[1].pop();
			}
			if (!v[1].empty()) {
				result.push_back(v[1]);
			}
		}
		return result;
	}
};