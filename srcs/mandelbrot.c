/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:37:34 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/01/04 20:31:30 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			ft_init(t_env *env, t_num_comp *c, t_num_comp *z)
{
	long double		zoom_x;
	long double		zoom_y;

	zoom_x = (TEST_X) / (env->p2->x - env->p1->x);
	zoom_y = (TEST_Y) / (env->p2->y - env->p1->y);
	c->r = (long double)env->x / zoom_x + env->p1->x;
	c->i = (long double)env->y / zoom_y + env->p1->y;
	z->r = 0;
	z->i = 0;
}

static int			ft_unity(t_num_comp *c, t_num_comp *z)
{
	int				i;
	long double		tmp;

	i = 0;
	while (i < I_MAX && ((z->r * z->r + z->i * z->i) < 4))
	{
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = 2 * z->i * tmp + c->i;
		i++;
	}
	return (i);
}

void				ft_mandelbrot(t_env *event)
{
	t_num_comp		*z;
	t_num_comp		*c;

	event->x = event->mvt->x;
	event->y = event->mvt->y;
	printf("coordonnees de depart x = %f et y = %f\n", event->x, event->y);
	c = (t_num_comp *)malloc(sizeof(t_num_comp));
	z = (t_num_comp *)malloc(sizeof(t_num_comp));
	ft_init(event, c, z);
	while (event->x < (WIN_X + event->mvt->x))
	{
		while (event->y < (WIN_Y + event->mvt->y))
		{
			ft_init(event, c, z);
			event->i = ft_unity(c, z);
			 if (event->i == I_MAX)
			 {
				event->data[(int)event->y * event->sizeline + (int)event->x * event->bpp / 8] = 0x0;
				event->data[(int)event->y * event->sizeline + (int)event->x * event->bpp / 8 + 1] = 0x0;
				event->data[(int)event->y * event->sizeline + (int)event->x * event->bpp / 8 + 2] = 0x0;
			 }
			 else
				ft_put_pixel(event);
			(event->y)++;
		}
		(event->x)++;
		event->y = event->mvt->y;
	}
	printf("coordonnees de fin x = %f et y = %f\n", event->x, event->y);
	free(c);
	free(z);
}
