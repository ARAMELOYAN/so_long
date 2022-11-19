/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:43:57 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/01 16:42:23 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_uint(unsigned int u, t_struct *my_var, int fd)
{
	char	c;

	if (u < 10)
	{
		c = u + 48;
		write(fd, &c, 1);
		(*my_var).count++;
		return ;
	}
	pr_uint(u / 10, my_var, fd);
	pr_uint(u % 10, my_var, fd);
}
