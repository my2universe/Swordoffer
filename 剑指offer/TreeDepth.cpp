//����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ��
//��������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
//���ַ���������Ⱥ͹�����ȶ�������


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/**********************************�������DFS********************************************/
//˼·�����õݹ���������ڵ����Ϊ1����ô�������Ȼ��������������ȼ�һ�����������������������������ȼ��ԣ�
//��������������������������ȼ�һ�����������������ڣ���ô�ͱȽ��������������Ȼ���ټ�һ
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
		//��һ�εݹ��ʱ��Ը��ڵ�ֳ�������������Ȼ���Ƚ��������������������ݹ����ٽ������������еݹ�
	{
		if (pRoot == NULL) {
			return 0;
		}
		int left = TreeDepth(pRoot->left);//��������������
		int right = TreeDepth(pRoot->right);//���������������
		return (left > right) ? (left + 1) : (right + 1);
	}
};
/***************************************�����������****************************************/
//���˶���
//��ʵ������̾��ǰ��㽫ÿһ��Ľڵ�ŵ�������ߣ�
//Ȼ����ȡ��������Ľ���һ��Ž�ȥ��depth���ϼ�һ�����ջ�������������
//����ͻȻ���ǵ��˵����͵ݹ������
//������ѭ��
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return 0;
		}
		queue<TreeNode*	> que;
		int depth = 0;
		que.push(pRoot);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) { 
				TreeNode* node = que.front();
				que.pop();
				if (node->left) {
					que.push(node->left);
				}
				if (node->right) {
					que.push(node->right);
				}
			}
		}
		return depth;
	}
};