#include <stdio.h>


void	ft_swap(int *arr, int a, int b)
{
	int	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void	quick(int *arr, unsigned int start, unsigned int end)
{
	unsigned int	left;
	unsigned int	right;
	int				pivot;

	if (start >= end || (end + 1) == 0)
		return ;
	left = start + 1;
	right = end;
	pivot = arr[start];
	while (left <= right)
	{
		while (arr[left] <= pivot)
			++left;
		while (arr[right] > pivot)
			--right;
		if (left <= right)
			ft_swap(arr, left, right);
	}
	ft_swap (arr, start, right);
	quick(arr, start, right - 1);
	quick(arr, right + 1, end);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	quick(tab, 0, size - 1);
}

int		main(void)
{
	int a[13] = {-2, -5, -100, -99, -99, 0, 50, 2000, 1, 1,2,1,1};
	int i = 0;
	int size = 13;

	sort_int_tab(a, size);
	while (i < size)
		printf("%d, ", a[i++]);
	return (0);
}
