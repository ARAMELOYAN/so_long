/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:36:58 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/02 17:38:56 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	pr_ulhex(unsigned long int c, char x, t_struct *my_var, int fd)
{
	char	*s;

	s = "abcdef";
	if (c < 10)
	{
		ft_putnbr_fd(c, fd);
		(*my_var).count++;
	}
	else if (c < 16)
	{
		if (x == 'X')
			ft_putchar_fd(ft_toupper(s[c - 10]), fd);
		else
			ft_putchar_fd(s[c - 10], fd);
		(*my_var).count++;
	}	
	else
	{
		pr_ulhex(c / 16, x, my_var, fd);
		pr_ulhex(c % 16, x, my_var, fd);
	}
}
