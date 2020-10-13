#include <stdlib.h>
#include <stdio.h>

int		*ft_rrange(int start, int end)
{
	int	*arr;
	int size;
	int i;

	i = 0;
	if (end > start)
	{
		size = end - start + 1;
		arr = (int *)malloc(sizeof(int) * size);
		while (end >= start)
		{
			arr[i] = end;
			--end;
			++i;
		}
	}
	else if (start == end)
	{
		arr = (int *)malloc(sizeof(int) * 1);
		arr[0] = start;
	}
	else
	{
		size = start - end + 1;
		arr = (int *)malloc(sizeof(int) * size);
		while (end <= start)
		{
			arr[i] = end;
			++end;
			++i;
		}
	}
	return (arr);
}

int		main(void)
{
	int *nums;
	int i;
	int len;
	int start;
	int end;

	i = 0;
	start = -10;
	end = -5;
	len = (end - start);
	if (start < 0 && end < 0)
		len = ((start * -1) - (end * -1));
	nums = ft_rrange(start, end);
	while (i <= len)
	{
		printf("%d\n", nums[i]);
		i++;
	}
	return (0);
}
