/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:30:47 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/12/29 14:39:55 by jrasoloh         ###   ########.fr       */
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

void				zoom_in(t_env *e)
{
//	e->x += WIN_X / 2;
//	e->y += WIN_Y / 2;
	e->x = e->x * 1.2;
	e->y = e->y * 1.2;
}

void				zoom_out(t_env *e)
{
//	e->x -= WIN_X;
//	e->y -= WIN_Y / 2;
	e->x = e->x / 1.2;
	e->y = e->y / 1.2;
}

void				key_move(int k, t_env *e)
{
	if (k == KEY_UP)
		e->y += 10;
	if (k == KEY_DOWN)
		e->y -= 10;
	if (k == KEY_RIGHT)
		e->x += 10;
	if (k == KEY_DOWN)
		e->x -= 10;
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

static int			ft_key(int keycode, t_env *event)
{
	key_exit(keycode, event);
	key_move(keycode, event);
	key_zoom(keycode, event);
	expose_hook(event);
	return (0);
}

void				ft_mlx(t_env *event)
{
	event->zoom = 5;
	event->zoom_j = 500;
	event->bpp = 0;
	event->sizeline = 0;
	event->endian = 0;
	event->x = 0;
	event->y = 0;
	event->data = NULL;
	event->color = ft_color(255, 255, 255);
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
