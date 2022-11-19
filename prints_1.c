/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:33:15 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/15 11:33:22 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_closed(t_var *var)
{
	var->iter_i = 0;
	while (var->map[var->iter_i])
		free(var->map[var->iter_i++]);
	write(1, "ERROR\n The map must be closed!\n", 31);
	free(var->map);
	exit(1);
}

void	print_rectangular(t_var *var)
{
	write(2, "ERROR\n The map must be Rectangular!\n", 36);
	close(var->fd);
	var->iter_i = 0;
	while (var->map[var->iter_i])
		free(var->map[var->iter_i++]);
	free(var->map);
	exit(1);
}

void	print_coldnt_open(void)
{
	write(2, "ERROR\n I couldn't open the file\n", 32);
	exit(1);
}

void	print_end_ber(void)
{
	write(2, "ERROR\n the file name must end with .ber!\n", 41);
	exit(1);
}

void	print_gr_than_two(void)
{
	write(2, "ERROR\n The size of map must be greater than two!\n", 49);
	exit(1);
}
