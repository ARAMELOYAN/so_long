/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 03:42:28 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/16 17:42:39 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_str(char *s, void (*f)(char, int), t_struct *my_var, int fd)
{
	if (!s)
		pr_str("(null)", &ft_putchar_fd, my_var, fd);
	while (s && *s)
	{
		f(*(s++), fd);
		(*my_var).count++;
	}
	return ((*my_var).count);
}
