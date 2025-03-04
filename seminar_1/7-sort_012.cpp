#include <iostream>

void sort_array(int n, int *a)
{
	int low = 0, mid = 0, high = n - 1;
	while(mid <= high)
	{
		if(a[mid] == 0)
			std::swap(a[low++], a[mid++]);
		else if(a[mid] == 1)
			mid++;
		else
			std::swap(a[mid], a[high--]);
	}
}

int main()
{
	std::cout << "Input array size, array of 0, 1 and 2" << std::endl;

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
