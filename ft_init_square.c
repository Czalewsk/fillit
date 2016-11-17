/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:54:57 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/17 13:22:30 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_init_square(size_t nb)
{
	size_t		n;
	size_t		sq;
	size_t		last_case;
	char		**square;

	n = 0;
	sq = 3;
	if (nb > 1)
		while (nb * 4 < ft_square(sq))
			sq++;
	last_case = ft_square(sq) - 1;
	square = (char**)malloc(sizeof(char*) * sq);
	while (n < sq)
		square[n++]=ft_strnew(sq);
	n = 0;
	while (n <= last_case)
	{
		square[n / sq][n % sq] = '.';
		n++;
	}
	return (square);
}
