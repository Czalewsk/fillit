/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:45:14 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/15 17:48:05 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

#include "libft.h"
#include <sys/uio.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

int			ft_validate_file(char *str);
t_list		*ft_create_list(char *str);

#endif
