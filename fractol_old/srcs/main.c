/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:31:01 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/11/19 14:56:07 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				main(int argc, char **argv)
{
	t_env		*event;

	(void) argv[1];
	if (argc != 2)
		ft_arg_error(argc);
	else
	{
		event = (t_env *)malloc(sizeof(t_env));	
		ft_mlx(event);
	}
	return (0);
}
