/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:06:16 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/15 13:16:10 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_var *var)
{
	if (var->map[var->player.pos_y - 1][var->player.pos_x - 2] != '1')
	{
		if (change_image(2, 1, var))
		{
			func(var, 2, 1);
			var->player.pos_x--;
		}
	}
}

void	move_right(t_var *var)
{
	if (var->map[var->player.pos_y - 1][var->player.pos_x] != '1')
	{
		if (change_image(0, 1, var))
		{
			func(var, 0, 1);
			var->player.pos_x++;
		}
	}
}

void	move_up(t_var *var)
{
	if (var->map[var->player.pos_y - 2][var->player.pos_x - 1] != '1')
	{
		if (change_image(1, 2, var))
		{
			func(var, 1, 2);
			var->player.pos_y--;
		}
	}
}

void	move_down(t_var *var)
{
	if (var->map[var->player.pos_y][var->player.pos_x - 1] != '1')
	{
		if (change_image(1, 0, var))
		{
			func(var, 1, 0);
			var->player.pos_y++;
		}
	}
}
