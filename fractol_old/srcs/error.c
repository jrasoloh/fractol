/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:37:01 by jrasoloh          #+#    #+#             */
/*   Updated: 2017/11/17 20:35:02 by jrasoloh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_arg_error(int argc)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fractol fractale_name");
		exit(1);
	}
	return (0);
}
