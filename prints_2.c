/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:23:41 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/19 16:35:35 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_unrec(void)
{
	write(2, "ERROR\nUnrecognizable character\n", 31);
	exit(1);
}

void	print_char_quant(void)
{
	write(2, "ERROR\nMap character quantity error!\n", 36);
	exit(1);
}

void	print_map(t_var *var)
{
	while (var->map[var->iter_j])
	{
		var->iter_i = 0;
		while (var->map[var->iter_j][var->iter_i]
			&& var->map[var->iter_j][var->iter_i] != '\n')
		{
			if ((var->iter_i == 0 || var->iter_i == var->col - 1)
				&& (var->iter_j == 0 || var->iter_j == var->row - 1))
				var->xpm_link[5] = '2';
			else
				var->xpm_link[5] = '1';
			var->xpm_link[4] = var->map[var->iter_j][var->iter_i];
			var->img.img = mlx_xpm_file_to_image(var->mlx,
					var->xpm_link, &var->img.width, &var->img.height);
			if (!var->img.img)
				print_xpm(var->xpm_link, var);
			mlx_put_image_to_window(var->mlx, var->win,
				var->img.img, var->iter_i * 50, var->iter_j * 50);
			var->iter_i++;
			mlx_destroy_image(var->mlx, var->img.img);
		}
		var->iter_j++;
	}
}

void	print_size(t_var *var)
{
	write(2, "Map size must be less than 42x21\n", 33);
	var->iter_i = 0;
	while (var->map[var->iter_i])
		free(var->map[var->iter_i++]);
	exit(1);
}

void	print_xpm(const char *str, t_var *var)
{
	ft_printf("Error! I could'nt open file '%s'\n", str);
	mlx_destroy_window(var->mlx, var->win);
	var->iter_i = 0;
	while (var->map[var->iter_i])
		free(var->map[var->iter_i++]);
	free(var->map);
	free(var->xpm_link);
	free(move);
	exit(1);
}
