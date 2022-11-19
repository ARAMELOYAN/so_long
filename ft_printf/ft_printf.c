/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:52:39 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/16 17:00:06 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char		*ptr;
	t_struct	my_var;
	va_list		va_ptr;

	va_start(va_ptr, str);
	my_var.count = 0;
	while (str && *str)
	{
		ptr = ft_strchr(str, '%');
		if (ptr == str && *(++str) != '%')
		{
			str = ft_strchr(str, '%');
			if (!str)
				str = ft_strchr(ptr, '\0');
			mondat(ft_substr(ptr, 1, (int)(str - ptr) - 1), &my_var, va_ptr, 1);
		}
		else if (*str == '%' && ++str)
			pr_str("%", &ft_putchar_fd, &my_var, 1);
		if (!ptr)
			return (pr_str((char *)str, &ft_putchar_fd, &my_var, 1));
		while (str < ptr && ptr)
			pr_char((*(str++)), &ft_putchar_fd, &my_var, 1);
	}
	va_end(va_ptr);
	return (my_var.count);
}
