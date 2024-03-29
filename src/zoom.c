/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:18:44 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/30 21:18:04 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "../include/fract_ol.h"
#include<stdio.h>

long double	ft_get_zoom_point_comp(long double zoom_point_comp
, long double d_comp, int direction)
{
	long double		res;
	long double		base;

	base = 0.7;
	if (direction < 0)
		base = 1 / base;
	res = zoom_point_comp + d_comp * base;
	return (res);
}

t_fractal	ft_get_zoomed_fractal(t_fractal fractal
, t_vector zoom_point_coordinate, int direction)
{
	t_point_distances	distances;

	distances.top = fractal.top_left.y - zoom_point_coordinate.y;
	distances.bottom = zoom_point_coordinate.y
		- (fractal.top_left.y - fractal.dim.y);
	distances.left = zoom_point_coordinate.x - fractal.top_left.x;
	distances.right = (fractal.top_left.x + fractal.dim.x)
		- zoom_point_coordinate.x;
	fractal.top_left.x = ft_get_zoom_point_comp(zoom_point_coordinate.x,
			-distances.left, direction);
	fractal.top_left.y = ft_get_zoom_point_comp(zoom_point_coordinate.y,
			distances.top, direction);
	fractal.dim.x = zoom_point_coordinate.x + ft_get_zoom_point_comp(0,
			distances.right, direction) - fractal.top_left.x;
	fractal.dim.y = fractal.top_left.y - zoom_point_coordinate.y
		+ ft_get_zoom_point_comp(0, distances.bottom, direction);
	return (fractal);
}

t_vector	zoom_point_to_coordinte(t_fractal zoomed_fractal,
mlx_image_t *img, t_vector zoom_point_screen)
{
	t_vector	zoom_point_coordinate;

	zoom_point_coordinate.x = (zoomed_fractal.top_left.x)
		+ (zoom_point_screen.x)
		/ (img->width) * (zoomed_fractal.dim.x);
	zoom_point_coordinate.y = (zoomed_fractal.top_left.y)
		- (zoom_point_screen.y)
		/ (img->height) * zoomed_fractal.dim.y;
	return (zoom_point_coordinate);
}

void	ft_zoom(t_vector zoom_point_screen,
int direction, t_scroll_hook_param *shp)
{
	t_vector			zoom_point_coordinate;

	zoom_point_coordinate = zoom_point_to_coordinte(shp->fractal,
			shp->img, zoom_point_screen);
	shp->fractal = ft_get_zoomed_fractal(shp->fractal,
			zoom_point_coordinate, direction);
	ft_draw_fractal2(shp->img, shp->fractal);
}
