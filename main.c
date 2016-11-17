/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:46:24 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/17 12:40:54 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*str;
	t_list	**start;
	t_list	*current;
	int		y = 0;

	if (ac != 2)
		ft_putendl_fd("usage : ", 2);
	else
		str = ft_get_it(av[1]);
	if (!(start = ft_validate_file(str)))
		ft_putendl_fd("error invalide file ", 2);
	if (!start)
		return (0);
	/*		 Test && Affichage temporaire */
	current = *start;
	printf("Nombre de tetra=%zu\n", ft_lstlen(current));
	while (current->next)
	{
		while (y <= 3)
			printf("%s\n", ((char**)(current->content))[y++]);
		current = current->next;
		y = 0;
		printf("\n");
	}
	while (y <= 3)
		printf("%s\n", ((char**)(current->content))[y++]);
	printf("\n");
	current = ft_lstmap(*start, &ft_get_coord);
	while (current->next)
	{
		y = 0;
		while (y < 5)
		{
			printf("l=%i | c =%i\n", ((int*)(current->content))[y], ((int*)(current->content))[y + 1]);
			y += 2;
		}
		printf("-----\n");
		current = current->next;
	}
	y = 0;
	while (y < 5)
	{
		printf("l=%i | c =%i\n", ((int*)(current->content))[y], ((int*)(current->content))[y + 1]);
		y += 2;
	}

	printf("OK\n");
	return (0);
}
