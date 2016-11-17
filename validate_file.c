/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:18:02 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/16 15:09:16 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valide_line(char *str)
{
	int		n;

	n = 0;
	while (*str)
	{
		if (*str == 35 || *str == 46)
			n++;
		else if (n == 0 && *str == 10 && *(str + 1) == 10)
			return (0);
		else if ((n == 4 || n == 0) && *str == 10)
			n = 0;
		else
			return (0);
		str++;
	}
	return (1);
}

int		valide_nb_sharp_point(char *str)
{
	int		nsharp;
	int		npoint;

	npoint = 0;
	nsharp = 0;
	while (*str)
	{
		if (*str == 35)
			nsharp++;
		else if (*str == 46)
			npoint++;
		else if (*str != '\n')
			return (0);
		str++;
	}
	if (npoint % 12 != 0)
		return (0);
	if (nsharp % 4 != 0)
		return (0);
	return (1);
}

int		ft_check_case(int l, int c, char **tetra)
{
	int		n;

	n = 0;
	if ((l - 1) != -1 && (tetra[l - 1][c] == 35))
		n++;
	if ((l + 1) != 4 && (tetra[l + 1][c] == 35))
		n++;
	if ((c - 1) != -1 && (tetra[l][c - 1] == 35))
		n++;
	if ((c + 1) != 4 && (tetra[l][c + 1] == 35))
		n++;
	return (n);
}

int		ft_valide_tetra(t_list **start)
{
	int			n;
	int			i;
	t_list		*current;

	current = *start;
	while (current->next)
	{
		i = -1;
		n = 0;
		while (++i <= 15)
			if (((char**)current->content)[i / 4][i % 4] == 35)
				n += ft_check_case((i / 4), i % 4, (char**)current->content);
		if (n < 6 || n > 8)
			return (0);
		current = current->next;
	}
	n = 0;
	i = -1;
	while (++i <= 15)
		if (((char**)current->content)[i / 4][i % 4] == 35)
			n += ft_check_case((i / 4), i % 4, (char**)current->content);
	if (n < 6 || n > 8)
		return (0);
	return (1);
}

t_list	**ft_validate_file(char *str)
{
	t_list		**start;

	if (!str)
		return (NULL);
	if (valide_nb_sharp_point(str) == 0 || valide_line(str) == 0)
		return (NULL);
	start = ft_create_list(str);
	if (ft_valide_tetra(start) == 0)
		start = NULL;
	return (start);
}
