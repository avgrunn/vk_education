#include <iostream>

std::pair<int, int> twoSum(int n, int *nums, int target)
{
	int left = 0, right = n - 1;
	while(left < right)
	{
		int sum = nums[left] + nums[right];
		if(target < sum)
			right--;
		else if(sum < target)
			left++;
		else
			return {left, right};
	}
	return {-1, -1};
}

int main()
{
	std::cout << "Input array size, sorted array and target value" << std::endl;

	int n, *a, target;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> target;

	std::pair<int, int> res = twoSum(n, a, target);
	if(res.first == -1)
		std::cout << "Not found";
	else
		std::cout << "Indexes: " << res.first << ' ' << res.second;
	std::cout << std::endl;

	delete[] a;
    return 0;
}
