#include <iostream>

int findSum(int* nums, int i);

int main() {
	int nums[4] = {1, 4, 5, 6};
	std::cout << findSum(nums, 4);
	return 0;
}

int findSum(int* nums, int i) {
	if (i <= 0) {
		return 0;
	}
	return findSum(nums, i - 1) + nums[i - 1];
}