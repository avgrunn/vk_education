#include <iostream>

void sort_array(int n, int *a)
{
	int left = 0;
	int right = n - 1;
	while(left < right)
	{
		if(a[left] == 1)
			std::swap(a[left], a[right--]);
		else
			left++;
	}
}

int main()
{
	std::cout << "Input array size, array of 0 1" << std::endl;

	int n, *a;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	sort_array(n, a);
	std::cout << "Sorted array:" << std::endl;
	for(int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;

	delete[] a;
    return 0;
}
