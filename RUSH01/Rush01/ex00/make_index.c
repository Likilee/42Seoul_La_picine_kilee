/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilee <gnsdlrl@daum.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:30:33 by kilee             #+#    #+#             */
/*   Updated: 2020/08/08 17:03:33 by kilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	**make_vp_index(int **vp_index, char *rm_space)
{
	int i;
	
	i = 0;
	while(rm_space[i])
	{
		if (i <= 4)
		{
			*vp_index[0] = rm_space[i] - '0';
			vp_index[0]++;
		}
		else if (i <= 8)
		{
			*vp_index[1] = rm_space[i] - '0';
			vp_index[1]++;
		}
		else if (i <= 12)
		{
			*vp_index[2] = rm_space[i] - '0';
			vp_index[2]++;
		}
		else
		{
			*vp_index[3] = rm_space[i] - '0';
			vp_index[3]++;
		}
		i++;
	}
	return (vp_index);
}


int main(void)
{
	int col_up[5];
	int col_down[5];
	int row_left[5];
	int row_right[5];
	int *vp_index[5];

	vp_index[0] = col_up;
	vp_index[1] = col_down;
	vp_index[2] = row_left;
	vp_index[3] = row_right;

	make_vp_index(vp_index, "1234123443214321");
	return 0;
}
