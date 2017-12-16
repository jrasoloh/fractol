/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:27:46 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/12/15 17:05:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_put_pixel(t_env *env)
{
	int				res;
	int				*tab;

	tab = (int*)env->data;
	res = env->x + (env->y * WIN_X);
	if (env->x >= 0 && env->x < WIN_X && env->y >= 0 && env->y < WIN_Y)
	{
		tab[res] = 0x001E90FF;
	}
}
