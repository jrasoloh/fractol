/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:58:06 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/01/04 20:15:46 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			zoom_in(t_env *e)
{
	e->p1->x = e->p1->x * 1.1;
	e->p1->y = e->p1->y * 1.1;
	e->p2->x = e->p2->x * 1.1;
	e->p2->y = e->p2->y * 1.1;
	e->p2_j->x = e->p2_j->x * 1.1;
	e->p2_j->y = e->p2_j->y * 1.1;
}

static void			zoom_out(t_env *e)
{
	e->p1->x = e->p1->x / 1.1;
	e->p1->y = e->p1->y / 1.1;
	e->p2->x = e->p2->x / 1.1;
	e->p2->y = e->p2->y / 1.1;
	e->p2_j->x = e->p2_j->x / 1.1;
	e->p2_j->y = e->p2_j->y / 1.1;
}

void				key_move(int k, t_env *e)
{
	if (k == KEY_UP)
//		e->mvt->y = e->mvt->y - 100;
	{
		e->p1->y = e->p1->y + 0.01;
		e->p2->y = e->p2->y + 0.01;
	}
	if (k == KEY_DOWN)
	{
		e->p1->y = e->p1->y - 0.01;
		e->p2->y = e->p2->y - 0.01;
	}
	if (k == KEY_RIGHT)
		e->mvt->x = e->mvt->x + 100;
	if (k == KEY_LEFT)
		e->mvt->x = e->mvt->x - 100;
}

void				key_zoom(int k, t_env *e)
{
	if (k == ZOOM_IN)
		zoom_in(e);
	if (k == ZOOM_OUT)
		zoom_out(e);
}

int					red_cross(t_env *event)
{
	ft_memdel((void**)&event);
	exit(0);
}
