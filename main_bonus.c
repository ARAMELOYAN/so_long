/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:48:57 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/18 12:24:07 by aeloyan          ###   ########.fr       */
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
	if (var->map[var->player.pos_y - b][var->player.pos_x - a] == 'G' )
		lose(var);
	if (var->map[var->player.pos_y - b][var->player.pos_x - a] == 'E' )
	{
		if (var->quant.collectable == 0)
			ft_printf("\t\tThank you Mario!!!\n\tBut our princess%s",
				" is another castle!!!\nYOU WON!!!\n");
		else
			return (0);
		my_exit(var);
	}
	var->xpm_link[4] = 'p';
	if (var->keycode == 2 || var->keycode == 124)
		var->xpm_link[5] = '1';
	else if (var->keycode == 0 || var->keycode == 123)
		var->xpm_link[5] = '2';
	return (1);
}

void	func(t_var *var, int a, int b)
{
	var->img.img = mlx_xpm_file_to_image(var->mlx,
			var->xpm_link, &var->img.width, &var->img.height);
	if (!var->img.img)
		print_xpm(var->xpm_link, var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img,
		(var->player.pos_x - a) * 50, (var->player.pos_y - b) * 50);
	mlx_destroy_image(var->mlx, var->img.img);
	var->quant.moves++;
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
	char	*s;

	var->keycode = keycode;
	move[keycode](var);
	var->img.img = mlx_xpm_file_to_image(var->mlx, "xpm/11.xpm",
			&var->img.width, &var->img.height);
	if (!var->img.img)
		print_xpm("xpm/11.xpm", var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img,
		(var->col / 2 + 2) * 50, 0);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 2 * 50, 0);
	mlx_destroy_image(var->mlx, var->img.img);
	s = ft_itoa(var->quant.moves);
	mlx_string_put(var->mlx, var->win, 2 * 50, 13,
		0x0000ff00, s);
	free(s);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;

	initialize(av, ac, &var);
	mlx_key_hook(var.win, key_hook, &var);
	print_map(&var);
	mlx_string_put(var.mlx, var.win, 0, 13, 0x0000ff00, "Moves:    0");
	mlx_hook(var.win, 17, 1L << 0, my_close, &var);
	mlx_loop(var.mlx);
	return (0);
}
