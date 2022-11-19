/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:35:09 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/02 18:12:16 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_addr(void *ptr, t_struct *my_var, int fd)
{
	uintptr_t	p_hex;

	p_hex = (uintptr_t)ptr;
	pr_str("0x", &ft_putchar_fd, my_var, fd);
	pr_ulhex(p_hex, 'x', my_var, fd);
}
