#include <iostream>

bool is_subsequence(int n, int *a, int m, int *b)
{
	int i = 0, j = 0;
	while(i < n && j < m)
	{
		if(a[i] == b[j])
			i++;
		j++;
	}
	return (i == n);
}

int main()
{
	std::cout << "Input array size, array of integers, then another array size and array of integers" << std::endl;
	int n, m, *a, *b;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> m;
	b = new int[m];
	for(int i = 0; i < m; i++)
		std::cin >> b[i];

	if(is_subsequence(n, a, m, b))
		std::cout << "Is a subsequence";
	else
		std::cout << "Not a subsequence";
	std::cout << std::endl;

	delete[] a;
	delete[] b;
	return 0;
}