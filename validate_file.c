/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:18:02 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/15 17:48:22 by czalewsk         ###   ########.fr       */
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
	while(*str)
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

int		ft_validate_file(char *str)
{

	if (!str)
		return (0);
	if (valide_nb_sharp_point(str) == 0 || valide_line(str) == 0)
		return (0);
	return (1);
}
