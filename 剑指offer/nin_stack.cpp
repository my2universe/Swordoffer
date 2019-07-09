
class Solution {
public:
	void push(int value) {
		Data.push(value);
		if (Min.empty()) {
			Min.push(value);
		}
		if (Min.top() > value) {
			Min.push(value);
		}
	}
	void pop() {
		if (Data.top() == Min.top()) {
			Min.pop();
		}
		Data.pop();
	}
	int top() {
		return Data.top();
	}
	int min() {
		return Min.top();
	}
private:
	stack<int> Data;            //数据栈
	stack<int> Min;                //最小栈
};