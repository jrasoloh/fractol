/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:30:19 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/11/21 16:31:53 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_put_pixel(t_env *env, int x, int y)
{
	int				res;
	int				*tab;

	tab = (int*)env->data;
	res = x + (y * WIN_X);
	if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
	{
		tab[res] = 0x001E90FF;
	}
}

void				ft_init_num_comp(t_num_comp *c, t_num_comp *z, t_point *a)
{
	long double		zoom_x;
	long double		zoom_y;
	
	zoom_x = TEST_X / (XX - X);
	zoom_y = TEST_Y / (YY - Y);
	c->r = (long double)a->x / (zoom_x + X);
	c->i = (long double)a->y / (zoom_y + Y);
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
	t_point			*a;
	int				i;

	a = (t_point *)malloc(sizeof(t_point));
	c = (t_num_comp *)malloc(sizeof(t_num_comp));
	z = (t_num_comp *)malloc(sizeof(t_num_comp));
	a->x = 0;
	a->y = 0;
	/*c.r = 0;
	c.i = 0;
	z.r = 0;
	z.i = 0;*/
	ft_init_num_comp(c, z, a);
	while (a->x < WIN_X)
	{
		while (a->y < WIN_Y)
		{
			ft_init_num_comp(c, z, a);
			i = ft_unity(c, z);
			if (i == I_MAX)
				ft_put_pixel(event, a->x, a->y);
			(a->y)++;
		}
		(a->x)++;
		a->y = 0;
	}

}
