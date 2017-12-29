/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:44:16 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/12/29 14:37:21 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			ft_init(t_env *env, t_num_comp *c, t_num_comp *z)
{
	int				zoom;

	zoom = 500;
	c->r = 0.285;
	c->i = 0.01;
	z->r = (long double)env->x / env->zoom_j + env->p2_j->x;
	z->i = (long double)env->y / env->zoom_j + env->p2_j->y;
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

void		ft_julia(t_env *event)
{
	t_num_comp		*z;
	t_num_comp		*c;

	c = (t_num_comp *)malloc(sizeof(t_num_comp));
	z = (t_num_comp *)malloc(sizeof(t_num_comp));
	ft_init(event, c, z);
	while (event->x < WIN_X)
	{
		while (event->y < WIN_Y)
		{
			ft_init(event, c, z);
			event->i = ft_unity(c, z);
			 if (event->i == I_MAX)
				ft_put_pixel(event);
			(event->y)++;
		}
		(event->x)++;
		event->y = 0;
	}
	free(c);
	free(z);
}
