/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:17:21 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/19 16:48:36 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_next_line(t_var *var)
{
	char	*buffer;
	char	*string;
	int		i;

	i = 0;
	buffer = (char *)malloc(var->size + 1);
	while (i < var->size && read(var->fd, &buffer[i], 1) == 1)
		if (buffer[i++] == '\n')
			break ;
	if (!i || i > 42 || var->row > 20)
	{
		free(buffer);
		var->map[var->row] = NULL;
		if (i > 42 || var->row > 20)
			print_size(var);
		return ;
	}
	if (buffer[i - 1] == '\n')
		buffer[i - 1] = '\0';
	else
		buffer[i] = '\0';
	string = ft_substr(buffer, 0, i);
	free(buffer);
	var->map[var->row] = string;
}

void	f_open(const char *str, t_var *var)
{
	char	*prefix;

	prefix = ft_strnstr(str, ".ber", ft_strlen(str));
	if (!prefix || ft_strlen(prefix) != 4)
		print_end_ber();
	var->fd = open(str, O_RDONLY);
	if (var->fd == -1)
		print_coldnt_open();
}

void	check_rectangle_error(t_var *var, void (*f)(char *, t_var *))
{
	var->row = 0;
	var->map = (char **)malloc(sizeof(char *) * (var->size + 1));
	get_next_line(var);
	if (!var->map[var->row])
		write(1, "Error: Your .ber file is empty!\n", 32);
	if (!var->map[var->row])
		exit(1);
	var->col = ft_strlen(var->map[var->row]);
	var->quant.player = 0;
	var->quant.collectable = 0;
	var->quant.exit = 0;
	while (var->map[var->row])
	{
		var->row++;
		var->iter_i = 0;
		var->closure_factor = 1;
		f(var->map[var->row - 1], var);
		get_next_line(var);
		if (var->map[var->row]
			&& ft_strlen(var->map[var->row]) != (size_t)var->col)
			print_rectangular(var);
	}
	if (!var->closure_factor)
		print_closed(var);
	close(var->fd);
}

void	check_the_closure(char *str, t_var *var)
{
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		print_closed(var);
	while (str[++var->iter_i])
	{
		if (str[var->iter_i] != '1')
			var->closure_factor = 0;
		if (str[var->iter_i] == 'P')
		{
			var->quant.player++;
			var->player.pos_x = var->iter_i + 1;
			var->player.pos_y = var->row;
		}
		else if (str[var->iter_i] == 'C')
			var->quant.collectable++;
		else if (str[var->iter_i] == 'E')
			var->quant.exit++;
		else if (str[var->iter_i] == '0'
			|| str[var->iter_i] == '1' || str[var->iter_i] == 'G')
			continue ;
		else
			print_unrec();
	}
	if (!var->closure_factor && var->row == 1)
		print_closed(var);
}

void	error(char **av, int ac, t_var *var)
{
	if (ac != 2)
		exit(1);
	f_open(av[1], var);
	var->size = 50;
	check_rectangle_error(var, &check_the_closure);
	if (var->row < 3 || var->col < 3)
		print_gr_than_two();
	if (var->quant.player != 1 || var->quant.collectable < 1
		|| var->quant.exit < 1)
		print_char_quant();
}
