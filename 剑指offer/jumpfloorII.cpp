class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0) {
			return 0;
		}
		int total = 1;
		for (int i = 1; i < number; i++) {
			total *= 2;
		}
		return total;
	}
};