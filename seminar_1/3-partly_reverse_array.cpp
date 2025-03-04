#include <iostream>

void reverse_part(int n, int *arr, int left, int right)
{
	while(left < right)
	{
		std::swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

void reverse_array(int n, int *arr, int k)
{
	k %= n;
	reverse_part(n, arr, 0, k);
	reverse_part(n, arr, k + 1, n - 1);
	reverse_part(n, arr, 0, n - 1);
}

int main()
{
	std::cout << "Input array size, an array and k index" << std::endl;
	int n, *a, k;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> k;

	reverse_array(n, a, k);
	std::cout << "Reversed array:" << std::endl;
	for(int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	delete[] a;
    return 0;
}
