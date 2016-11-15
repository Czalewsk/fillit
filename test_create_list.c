/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:46:57 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/15 17:50:57 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(void)
{
	int		y = 0;
	t_list		*current;
	char	s[] = "....\n####\n....\n....\n\n....\n####\n....\n....\n";

	printf("valide = %i\n", ft_validate_file(s));
	printf("111\n");
	current = ft_create_list(s);
	printf("222\n");
	printf("%c\n", ((char**)(current->content))[1][1]);
	printf("333\n");
/*	while(y < 32)
	{
		if (y % 4 == 0)
			printf("\n");
		printf("%c", ((char*)current->content)[y]);
		y++;
	}*/
	return (0);
}
