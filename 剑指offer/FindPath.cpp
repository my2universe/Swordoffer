//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ��ڵ㿪ʼһֱ��Ҷ�ڵ��������Ľڵ�
//��Ҫ�������鳤�ȴ�����鿿ǰ
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//ÿ�α����������Ȱ�root��ֵѹ��tmp��Ȼ���жϵ�ǰroot�Ƿ�ͬʱ���㣺
//�������ֵ���Ϊ0��
//������Ϊ�գ�
//������Ϊ�ա�
//��������������ͽ�tmpѹ��result�У��������α���������������Ҫע����ǣ�
//��������������ʱ��ȫ�ֱ���tmp�ǲ���յģ�ֱ�����˸��������tmp��
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
	{
		//��ʵ���ﷵ��resultû�����壬��ΪresultΪȫ�ֱ�����ȫ�̼�¼���������returnӦ��ֻ��Ϊ����һ��������˳�
		if (root==NULL)//��ζ�ŵ���Ҷ�ӽڵ���Ȼ�������γ�·�����������Ͱѵ�ǰ��result�Ľ����¼����������ȥ���������������ӽڵ�
		{
			return result;
		}
		tmp.push_back(root->val);
		if (expectNumber-(root->val) == 0 && root->left == NULL && root->right == NULL)
		{
			result.push_back(tmp);
		}
		FindPath(root->left, expectNumber - (root->val));
		FindPath(root->right, expectNumber - (root->val));
	}
private:
	vector<vector<int>>result;
	vector<int>tmp;
};