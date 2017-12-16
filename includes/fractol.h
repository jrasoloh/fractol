/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:44:42 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/12/16 17:57:20 by jrasoloh         ###   ########.fr       */
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
# define ZOOM_IN		69
# define ZOOM_OUT		78
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
	int					x;
	int					y;
}						t_point;

typedef struct			s_env
{
	int					*mlx;
	int					*win;
	int					color;
	int					zoom;
	int					bpp;
	void				*img_ptr;
	int					endian;
	int					sizeline;
	char				*data;
	int					x;
	int					y;
	int					i;
}						t_env;



/* ***************************************************************************

 * DISPLAY */
int						red_cross(t_env *event);
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

#endif
