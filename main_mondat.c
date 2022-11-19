/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mondat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:29:22 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/18 12:31:40 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	change_image(int a, int b, t_var *var)
{
	if (var->map[var->player.pos_y - b][var->player.pos_x - a] == 'C')
	{
		var->map[var->player.pos_y - b][var->player.pos_x - a] = '0';
		var->quant.collectable--;
	}
	if (var->map[var->player.pos_y - b][var->player.pos_x - a] == 'E')
	{
		if (var->quant.collectable == 0)
			ft_printf("\t\tThank you Mario!!!\n\tBut our princess%s",
				" is another castle!!!\nYOU WON!!!\n");
		else
			return (0);
		my_exit(var);
	}
	return (1);
}

void	func(t_var *var, int a, int b)
{
	var->img.img = mlx_xpm_file_to_image(var->mlx,
			"xpm/p1.xpm", &var->img.width, &var->img.height);
	if (!var->img.img)
		print_xpm("xpm/p1.xpm", var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img,
		(var->player.pos_x - a) * 50, (var->player.pos_y - b) * 50);
	mlx_destroy_image(var->mlx, var->img.img);
	var->quant.moves++;
	ft_printf("MOVES:\t%d\n", var->quant.moves);
	var->img.img = mlx_xpm_file_to_image(var->mlx,
			"xpm/01.xpm", &var->img.width, &var->img.height);
	if (!var->img.img)
		print_xpm("xpm/01.xpm", var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img,
		(var->player.pos_x - 1) * 50, (var->player.pos_y - 1) * 50);
	mlx_destroy_image(var->mlx, var->img.img);
}

int	key_hook(int keycode, t_var *var)
{
	move[keycode](var);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;

	initialize(av, ac, &var);
	mlx_key_hook(var.win, key_hook, &var);
	print_map(&var);
	mlx_hook(var.win, 17, 1L << 0, my_close, &var);
	mlx_loop(var.mlx);
	return (0);
}
