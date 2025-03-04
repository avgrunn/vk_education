#include <iostream>

void reverse_array(int n, int *arr)
{
	int left = 0, right = n - 1;
	while(left < right)
	{
		std::swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

int main()
{
	std::cout << "Input array size and an array" << std::endl;

	int n, *a;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	reverse_array(n, a);
	std::cout << "Reversed array:" << std::endl;
	for(int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	delete[] a;
    return 0;
}
