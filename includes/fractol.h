/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:44:42 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/01/04 18:49:27 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define WIN_X			1500
# define WIN_Y			1000
# define T_EXIT			53
# define ZOOM_OUT		69
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_LEFT		123
# define ZOOM_IN		78
# define X				-2.1
# define XX				0.6
# define X_J			-1
# define XX_J			1
# define Y				-1.2
# define YY				1.2
# define I_MAX			50
# define I_MAX_J		100
# define TEST_X			1500
# define TEST_Y			1000

typedef struct			s_num_comp
{
	long double			r;
	long double			i;
}						t_num_comp;

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct			s_env
{
	int					*mlx;
	int					*win;
	int					color;
	int					zoom;
	int					zoom_j;
	int					bpp;
	void				*img_ptr;
	int					endian;
	int					sizeline;
	char				*data;
	t_point				*p1;
	t_point				*p2;
	t_point				*p2_j;
	double				x;
	double				y;
	t_point				*mvt;
	int					i;
}						t_env;



/* ***************************************************************************

 * DISPLAY */
int						expose_hook(t_env *event);
void					ft_mlx(t_env *event);
/* ***************************************************************************

 * MANDELBROT */
void					ft_mandelbrot(t_env *event);
/* ***************************************************************************

 * JULIA */
void					ft_julia(t_env *env);
/* ***************************************************************************

 * TOOLS */
void					ft_put_pixel(t_env *env);
/* ***************************************************************************

 * ERROR */
int						ft_arg_error(int argc);
/* ***************************************************************************

 * GRAPHIC */
void					key_move(int k, t_env *e);
void					key_zoom(int k, t_env *e);
int						red_cross(t_env *event);
#endif
