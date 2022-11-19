/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:10:44 by aeloyan           #+#    #+#             */
/*   Updated: 2022/11/15 11:26:59 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_gomb(t_var *var)
{
	t_gomb	*gomb;
	t_gomb	*gomb_2;

	gomb = (t_gomb *)malloc(sizeof(t_gomb));
	gomb->pos_x = var->iter_i + 1;
	gomb->pos_y = var->row;
	gomb->next = NULL;
	if (var->quant.gomb == 0)
		var->gomb = gomb;
	else
	{
		gomb_2 = var->gomb;
		while (gomb_2->next)
			gomb_2 = gomb_2->next;
		gomb_2->next = gomb;
	}
	var->quant.gomb++;
}
