/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:38 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/22 02:38:40 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "MLX42/MLX42.h"

typedef struct s_complex
{
	long double	real;
	long double	imaginary;
}	t_complex;

typedef struct s_vector
{
	long double	x;
	long double	y;
}	t_vector;

typedef struct s_fractal
{
	t_vector	top_left;
	t_vector	top_right;
	t_vector	bottom_left;
}	t_fractal;

typedef struct s_point_distances
{
	long double	top;
	long double	bottom;
	long double	left;
	long double	right;
}	t_point_distances;

typedef struct s_scroll_hook_param
{
	mlx_image_t		*img;
	mlx_t			*mlx;
}	t_scroll_hook_param;


t_complex	*ft_add_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_subtract_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_multiply_complex(t_complex *c1, t_complex *c2, t_complex *res);

t_complex	*ft_divide_complex(t_complex *c1, t_complex *c2, t_complex *res);

long double		ft_squared_absolute_complex(t_complex c);

int			mandelbrot(t_complex c);

#endif
