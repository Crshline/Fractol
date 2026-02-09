/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:32:51 by jukeurme          #+#    #+#             */
/*   Updated: 2026/02/09 11:25:04 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

t_complex	pixel_to_complex(t_fractol *fractol, int x, int y)
{
	t_complex	c;

	c.a = (x - 500) / fractol->zoom + fractol->offset_x;
	c.b = (y - 500) / fractol->zoom + fractol->offset_y;
	return (c);
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			iteration;
	double		temp_a;
	double		temp_b;

	z.a = 0;
	z.b = 0;
	iteration = 0;
	while (iteration < 256)
	{
		temp_a = (z.a * z.a) - (z.b * z.b) + c.a;
		temp_b = (2 * z.a * z.b) + c.b;
		z.a = fabs(temp_a);
		z.b = fabs(temp_b);
		if ((z.a * z.a) + (z.b * z.b) > 4)
			break ;
		iteration++;
	}
	return (iteration);
}

int	julia(t_complex z, t_complex julia_c)
{
	int		iteration;
	double	temp_a;
	double	temp_b;

	iteration = 0;
	while (iteration < 256)
	{
		temp_a = (z.a * z.a) - (z.b * z.b) + julia_c.a;
		temp_b = (2 * z.a * z.b) + julia_c.b;
		z.a = temp_a;
		z.b = temp_b;
		if ((z.a * z.a) + (z.b * z.b) > 4)
			break ;
		iteration++;
	}
	return (iteration);
}
