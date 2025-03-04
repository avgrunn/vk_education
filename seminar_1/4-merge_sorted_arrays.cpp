#include <iostream>

int *merge_arrays(int n, int *a, int m, int *b)
{
	int k = n + m, i = 0, j = 0;
	int *merged_array = new int[k];
	for(int l = 0; l < k; l++)
	{
		if(i == n)
			merged_array[l] = b[j++];
		else if(j == m)
			merged_array[l] = a[i++];
		else if(a[i] < b[j])
			merged_array[l] = a[i++];
		else
			merged_array[l] = b[j++];
	}
	return merged_array;
}

int main()
{
	std::cout << "Input array size, sorted array, another array size and sorted array" << std::endl;

	int n, m, *a, *b;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> m;
	b = new int[m];
	for(int i = 0; i < m; i++)
		std::cin >> b[i];

	int *c = merge_arrays(n, a, m, b);
	int k = n + m;
	std::cout << "Merged arrays:" << std::endl;
	for(int i = 0; i < k; i++)
		std::cout << c[i] << ' ';
	std::cout << std::endl;

	delete[] a;
	delete[] b;
	delete[] c;
    return 0;
}
