/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:30:38 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/16 19:54:12 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*ft_get_coord(t_list *elem)
{
	int		i;
	int		coord[3][2];
	int		lo;
	int		co;
	int		n;

	lo = -1;
	co = -1;
	i = -1;
	n = 0;
	while (++i <= 15)
	{
		if (((char**)elem->content)[i % 4][i / 4] == 35 && lo < 0 && co < 0)
		{
			lo = i % 4;
			co = i / 4;
		}
		else if (((char**)elem->content)[i % 4][i / 4] == 35)
		{
			coord[n][0] = (i % 4) - lo;
			coord[n][1] = (i / 4) - co;
			n++;
		}
	}
	return (ft_lstnew(coord, sizeof(int) * 6));
}

char		**ft_tetra(char *s)
{
	size_t		i;
	size_t		n;
	char		**tetra;

	tetra = (char**)malloc(4 * sizeof(char*));
	i = 0;
	n = 0;
	while (i < 20)
	{
		if ((i % 5) == 0 && s[i] != 10)
			tetra[n++] = ft_strsub(&(s[i]), 0, 4);
		i++;
	}
	return (tetra);
}

t_list		**ft_create_list(char *str)
{
	t_list		**start;
	size_t		i;
	t_list		*new;
	char		**tetra;

	i = 0;
	if (!str)
		return (NULL);
	if (!(start = (t_list**)malloc(sizeof(t_list**))))
		return (NULL);
	*start = NULL;
	while (str[i])
	{
		if (i % 21 == 0)
		{
			tetra = ft_tetra(&(str[i]));
			new = ft_lstnew(tetra, sizeof(char*) * 4);
			ft_lst_pushend(start, new);
		}
		i++;
	}
	return (start);
}
