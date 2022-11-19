/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:35:01 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/19 16:35:06 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf/ft_printf.h" 
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}		t_player;

typedef struct s_gomb
{
	int				pos_x;
	int				pos_y;
	struct s_gomb	*next;
}					t_gomb;

typedef struct s_quant
{
	int	collectable;
	int	player;
	int	exit;
	int	moves;
	int	gomb;
}		t_quant;

typedef struct s_img
{
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_var
{
	char		**map;
	char		*xpm_link;
	void		*mlx;
	void		*win;
	t_img		img;
	t_gomb		*gomb;
	t_quant		quant;
	t_player	player;
	int			closure_factor;
	int			keycode;
	int			iter_i;
	int			iter_j;
	int			size;
	int			row;
	int			col;
	int			fd;
}				t_var;

void	initialize(char **av, int ac, t_var *var);
void	print_xpm(const char *str, t_var *var);
void	error(char **av, int ac, t_var *var);
void	func(t_var *var, int a, int b);
void	print_rectangular(t_var *var);
void	(**move)(t_var *var);
void	my_exit(t_var *var);
void	lose(t_var *var);
void	move_left(t_var *var);
void	move_right(t_var *var);
void	move_up(t_var *var);
void	move_down(t_var *var);
void	print_closed(t_var *var);
void	print_coldnt_open(void);
void	print_end_ber(void);
void	print_gr_than_two(void);
void	print_unrec(void);
void	print_char_quant(void);
void	print_map(t_var *var);
void	print_size(t_var *var);
void	add_player(t_var *var);
void	new_gomb(t_var *var);
int		change_image(int a, int b, t_var *var);
int		key_hook(int keycode, t_var *var);
int		my_close(t_var *var);

#endif
