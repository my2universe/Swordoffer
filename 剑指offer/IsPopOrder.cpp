//借助一个辅助栈，遍历压栈顺序判断栈顶元素是不是出栈顺序的第一个元素，
//若是就出栈，如不是就继续压栈，知道压栈元素和出栈顺序的第一个和元素相等，
//则出栈一个元素，并将出栈顺序向后移一位，然后继续判断，循环后若出栈不空，
//则署名弹出序列不是该站弹出顺序
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0) {
			return false;
		}
		for (int i = 0, j = 0; i < pushV.size(); i++) {
			stackData.push(pushV[i]);
			while (j < popV.size() && stackData.top() == popV[j]) {
				//开始写的时候不知道怎么处理循环条件，一次仅弹出一个的话，
				//循环次数不够，再循环到当前弹出序列的时候，只要有栈顶元素和出栈顺序相同就弹出
				stackData.pop();
				j++;
			}
		}
		return stackData.empty();
	}
private:
	stack<int> stackData;
};