/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:27:46 by jrasoloh          #+#    #+#             */
/*   Updated: 2018/01/04 20:31:32 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_put_pixel(t_env *env)
{
//	static int		i;
	//int				res;
	//int				*tab;

	//tab = (int*)env->data;
	//res = env->x + (env->y * WIN_X);
//	if (env->x >= 0 && env->x < WIN_X && env->y >= 0 && env->y < WIN_Y)
//	{
	//	tab[] = 0x001E90FF;
		//tab[res] = 0xff + i;
		env->data[(int)env->y * env->sizeline + (int)env->x * env->bpp / 8] = env->i / 3 * 6 * 0.42;
		env->data[(int)env->y * env->sizeline + (int)env->x * env->bpp / 8 + 1] = env->i / 3 * 6 * 4.2;
		env->data[(int)env->y * env->sizeline + (int)env->x * env->bpp / 8 + 2] = env->i / 3 * 6 * 42;
//		i++;
//	}
}
