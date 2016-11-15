/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:30:38 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/15 17:50:30 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_create_tetra(void)
{
	char	**tetra;
	int		y;

	tetra = (char**)malloc(sizeof(char**) * 4);
	y = 0;
	while (y <= 4)
		tetra[y++] = (char*)malloc(sizeof(char*) * 4);
	return (tetra);
}

t_list		*ft_create_list(char *str)
{
	char	**tetra;
	int		x = 0;
	int		y = 0;
	t_list	*start;

	start = NULL;
	tetra = ft_create_tetra();
	while (*str)
	{
		if (*str == '\n')
		{
			x = 0;
			y++;
			if (*(str + 1) == '\n')
			{
				y = 0;
				x = 0;
				ft_lst_pushend(&start, ft_lstnew(tetra, sizeof(tetra)));
			}
		}
		else
		{
			printf("x=%i | y=%i | char=%c\n", x, y, *str);
			tetra[x++][y] = *str;
		}
		str++;
	}
	return (start);
}
