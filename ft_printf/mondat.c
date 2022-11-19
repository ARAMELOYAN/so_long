/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:26:46 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/15 20:42:39 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mondat(char *s, t_struct *my_var, va_list va_ptr, int fd)
{
	char	*for_free;
	char	*for_itoa_free;

	for_free = s;
	if (*s == 'd' || *s == 'i')
	{
		for_itoa_free = ft_itoa(va_arg(va_ptr, int));
		pr_str(for_itoa_free, &ft_putchar_fd, my_var, fd);
		free(for_itoa_free);
	}
	else if (*s == 'c')
		pr_char(va_arg(va_ptr, int), &ft_putchar_fd, my_var, fd);
	else if (*s == 's')
		pr_str(va_arg(va_ptr, char *), &ft_putchar_fd, my_var, fd);
	else if (*s == 'u')
		pr_uint(va_arg(va_ptr, unsigned int), my_var, fd);
	else if (*s == 'p')
		pr_addr(va_arg(va_ptr, void *), my_var, fd);
	else if (*s == 'x' || *s == 'X')
		pr_hex(va_arg(va_ptr, int), *s, my_var, fd);
	else
		pr_char(*s, &ft_putchar_fd, my_var, fd);
	pr_str(++s, &ft_putchar_fd, my_var, fd);
	free(for_free);
}
