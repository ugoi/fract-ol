/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:02:47 by sdukic            #+#    #+#             */
/*   Updated: 2022/12/05 08:40:25 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#include <math.h>
#include <stdio.h>
#include "../lib/libft/libft.h"
#include "../lib/libft/ft_printf.h"

int	ft_sinus_colors(int iterations, float shift)
{
	if (iterations == 0)
		return (255);
	else
	{
		return (
			get_rgba(
				((sin(iterations * 0.8 + 3.0 + shift) + 1.0) / 2.0 * 255.0),
				((sin(iterations * 0.5 + 4.0 + shift) + 1.0) / 2.0 * 255.0),
				((sin(iterations * 0.3 + 1.0 + shift) + 1.0) / 2.0 * 255.0),
				255));
	}
}

int	ft_ordered_linear_colors(int iterations)
{
	if (iterations == 0)
		return (255);
	else
	{
		return ((RGB_MAX * iterations / ITER << 8) | 255);
	}
}

void	shift_color(t_scroll_hook_param *shp, long double translation)
{
	shp->fractal.col_shift += translation;
	ft_draw_fractal2(shp->img, shp->fractal);
	return ;
}
