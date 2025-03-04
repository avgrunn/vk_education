#include <iostream>

void merge_arrays(int k, int *c, int m, int *b)
{
	int n = k - m;
	int i = n - 1, j = m - 1;
	for(int l = k - 1; l >= 0; l--)
	{
		if(i == -1)
			c[l] = b[j--];
		else if(j == -1)
			c[l] = c[i--];
		else if(c[i] > b[j])
			c[l] = c[i--];
		else
			c[l] = b[j--];
	}
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

	int k = n + m;
	int *c = new int[k];
	for(int i = 0; i < n; i++)
		c[i] = a[i];
	for(int i = n; i < k; i++)
		c[i] = 0;

	merge_arrays(k, c, m, b);
	std::cout << "Merged arrays:" << std::endl;
	for(int i = 0; i < k; i++)
		std::cout << c[i] << ' ';
	std::cout << std::endl;

	delete[] a;
	delete[] b;
	delete[] c;
    return 0;
}
