/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:46:24 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/15 15:45:07 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buffer;
	char	*str;
	size_t	i;
	t_list	**start;
	t_list	*current;
	int		x = 0;
	int		y = 0;

	str = ft_strnew(651);
	i = 0;
	if (ac != 2)
		ft_putendl_fd("usage : ", 2);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_putendl_fd("error fd = -1 : ", 2);
		else
			while (read(fd, &buffer, 1))
				str[i++] = buffer;
	}
	if (!(start = ft_validate_file(str)))
		ft_putendl_fd("error invalide file ", 2);
	current = *start;
	printf("main11\n");
	while (current->next)
	{
		while (y <= 3)
		{
			while (x <= 3)
				printf("%c", ((char**)current->content)[x][y++]);
			if (y == 4)
			{
				printf("\n");
				x = 0;
				y++;
			}
		}
		current = current->next;
	}
	printf("%s\n", ((char*)current->content));
	return (0);
}
