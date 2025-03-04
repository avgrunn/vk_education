#include <iostream>

void sort_array(int n, int *a)
{
	int nonzero_ind = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] != 0)
			a[nonzero_ind++] = a[i];
	}
	for(int i = nonzero_ind + 1; i < n; i++)
		a[i] = 0;
}

int main()
{
	std::cout << "Input array size, array of numbers and zeros" << std::endl;

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
