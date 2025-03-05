#include <iostream>

bool is_palindrome(int n, int *a)
{
	int left = 0;
	int right = n - 1;
	while(left < right)
	{
		if(a[left] != a[right])
			return 0;
		left++;
		right--;
	}
	return 1;
}

int main()
{
	std::cout << "Input array size and an array of integers" << std::endl;
	int n, *a;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	if(is_palindrome(n, a))
		std::cout << "Is a palindrome";
	else
		std::cout << "Not a palindrome";
	std::cout << std::endl;

	delete[] a;
	return 0;
}