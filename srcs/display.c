/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:30:47 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/01/04 18:54:11 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			ft_color(int r, int g, int b)
{
	int				color;

	color = 0;
	color += ((r << 16) + (g << 8) + b);
	return (color);
}

void				key_exit(int keycode, t_env *e)
{
	if (keycode == T_EXIT)
	{
		free(e);
		exit(0);
	}
}

int					expose_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	ft_bzero(e->data, WIN_Y * e->sizeline);
	e->img_ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_mandelbrot(e);
//	ft_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_string_put(e->mlx, e->win, WIN_X / 2, 0, 0x00CD853F, "MY_FRACTOL");
	return (0);
}

static int			ft_key(int k, t_env *e)
{
	printf("keycode = %d/ x = %f; y = %f \n", k, e->mvt->x, e->mvt->y);
	key_exit(k, e);
	key_move(k, e);
	key_zoom(k, e);
	expose_hook(e);
	return (0);
}

void				ft_mlx(t_env *event)
{
	event->zoom = 5;
	event->zoom_j = 500;
	event->bpp = 0;
	event->sizeline = 0;
	event->endian = 0;
	event->data = NULL;
	event->color = ft_color(255, 255, 255);
	if (!(event->mvt = (t_point *)malloc(sizeof(t_point))))
		return ;
	else
	{
		event->mvt->x = 0;
		event->mvt->y = 0;
	}
	if (!(event->p1 = (t_point *)malloc(sizeof(t_point))))
		return ;
	else
	{
		event->p1->x = -2.1;
		event->p1->y = -1.2;
	}
	if (!(event->p2 = (t_point *)malloc(sizeof(t_point))))
		return ;
	else
	{
		event->p2->x = 0.6;
		event->p2->y = 1.2;
	}
	if (!(event->p2_j = (t_point *)malloc(sizeof(t_point))))
		return ;
	else
	{
		event->p2_j->x = -1;
		event->p2_j->y = -1.2;
	}
	event->mlx = mlx_init();
	event->win = mlx_new_window(event->mlx, WIN_X, WIN_Y, "mlx 42");
	if (!(event->img_ptr = mlx_new_image(event->mlx, WIN_X, WIN_Y)))
		return ;
	if (!(event->data = mlx_get_data_addr(event->img_ptr, &(event->bpp),
					&(event->sizeline), &(event->endian))))
		return ;
	mlx_put_image_to_window(event->mlx, event->win, event->img_ptr, 0, 0);
	mlx_hook(event->win, 17, (1L << 17), &red_cross, event);
	mlx_key_hook(event->win, ft_key, event);
	mlx_expose_hook(event->win, expose_hook, event);
	mlx_loop(event->mlx);
}
