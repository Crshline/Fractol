/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:32:51 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/26 13:06:23 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

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
	while (iteration < 50)
	{
		temp_a = (z.a * z.a) - (z.b * z.b) + c.a;
		temp_b = (2 * z.a * z.b) + c.b;
		z.a = temp_a;
		z.b = temp_b;
		if ((z.a * z.a) + (z.b * z.b) > 4)
			break ;
		iteration++;
	}
	return (iteration);
}

int	julia(t_complex z, t_complex julia_c)
{
	int			iteration;
	double		temp_a;
	double		temp_b;

	iteration = 0;
	while (iteration < 50)
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

int	get_color(int iteration)
{
	if (iteration == 50)
		return (0x00000000);
	return ((iteration * 10) << 16 | ((iteration * 5) << 8));
}

void	render(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	z_or_c;
	int			iteration;
	int			color;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			z_or_c = pixel_to_complex(fractol, x, y);
			if(ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
				iteration = mandelbrot(z_or_c);
			else if(ft_strncmp(fractol->name, "julia", 5) == 0)
				iteration = julia(z_or_c, fractol->julia_c);
			color = get_color(iteration);
			my_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connexion, fractol->mlx_windows,
		fractol->image_ptr, 0, 0);
}
