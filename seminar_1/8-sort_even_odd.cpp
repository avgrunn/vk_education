#include <iostream>

void sort_array(int n, int *a)
{
	int even_ind = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			std::swap(a[even_ind++], a[i]);
		}
	}
}

int main()
{
	std::cout << "Input array size, array of odd and even" << std::endl;

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
