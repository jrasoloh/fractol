/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:30:47 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/12/16 18:15:27 by jrasoloh         ###   ########.fr       */
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

int					red_cross(t_env *event)
{
	ft_memdel((void**)&event);
	exit(0);
}

int					expose_hook(t_env *event)
{
	ft_bzero(event->data, WIN_Y * event->sizeline);
//	ft_mandelbrot(event);
	ft_julia(event);
	mlx_put_image_to_window(event->mlx, event->win, event->img_ptr, 0, 0);
	mlx_string_put(event->mlx, event->win, WIN_X / 2, 0, 0x00CD853F, "MY_FRACTOL");
	return (0);
}

static int			ft_key(int keycode, t_env *event)
{
	if (keycode == T_EXIT)
	{
		free(event);
		exit(0);
	}
	if (keycode == ZOOM_IN && event->zoom > -1 && event->zoom <= 100)
		event->zoom += 5;
	if (keycode == ZOOM_OUT && event->zoom > 4 && event->zoom < 106)
		event->zoom -= 5;
	expose_hook(event);
	return (0);
}

void				ft_mlx(t_env *event)
{
	event->zoom = 5;
	event->bpp = 0;
	event->sizeline = 0;
	event->endian = 0;
	event->x = 0;
	event->y = 0;
	event->data = NULL;
	event->color = ft_color(255, 255, 255);
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
