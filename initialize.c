/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:32:18 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/18 13:19:40 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate(t_var *var)
{
	(void)var;
	return ;
}

void	lose(t_var *var)
{
	write(1, "\n\tYOU LOSE!!!\n", 14);
	my_exit(var);
}

void	my_exit(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	var->iter_i = 0;
	while (var->map[var->iter_i])
		free(var->map[var->iter_i++]);
	free(var->map);
	free(var->xpm_link);
	free(move);
	exit(0);
}

int	my_close(t_var *var)
{
	my_exit(var);
	return (0);
}

void	initialize(char **av, int ac, t_var *var)
{
	error(av, ac, var);
	move = malloc(sizeof(char *) * 300);
	var->iter_i = 0;
	while (var->iter_i < 300)
		move[var->iter_i++] = &animate;
	move[0] = &move_left;
	move[123] = &move_left;
	move[1] = &move_down;
	move[125] = &move_down;
	move[2] = &move_right;
	move[124] = &move_right;
	move[13] = &move_up;
	move[126] = &move_up;
	move[53] = &my_exit;
	var->quant.gomb = 0;
	var->quant.moves = 0;
	var->mlx = mlx_init();
	var->xpm_link = ft_strdup("xpm/11.xpm");
	var->win = mlx_new_window(var->mlx, var->col * 50,
			var->row * 50, "so_long");
	var->iter_j = 0;
}
