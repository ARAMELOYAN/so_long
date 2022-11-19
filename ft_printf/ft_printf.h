/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:30:13 by aeloyan           #+#    #+#             */
/*   Updated: 2022/07/16 16:37:57 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct my_str
{
	int		count;
}			t_struct;
int		ft_printf(const char *s, ...);
void	pr_char(char c, void (*f)(char, int), t_struct *my_var, int fd);
void	mondat(char *s, t_struct *my_var, va_list va_ptr, int fd);
void	pr_uint(unsigned int u, t_struct *my_var, int fd);
void	pr_addr(void *ptr, t_struct *my_var, int fd);
void	pr_hex(unsigned int c, char x, t_struct *my_var, int fd);
void	pr_ulhex(unsigned long int c, char x, t_struct *my_var, int fd);
int		pr_str(char *s, void (*f)(char, int), t_struct *my_var, int fd);
#endif
