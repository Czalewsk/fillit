/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:11:35 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/17 12:15:58 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_it(char *name)
{
	int		fd;
	char	buffer;
	char	*str;
	size_t	i;

	str = ft_strnew(1000);
	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("error fd = -1", 2);
	else
		while (read(fd, &buffer, 1))
			str[i++] = buffer;
	return (str);
}
