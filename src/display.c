/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:55:08 by jukeurme          #+#    #+#             */
/*   Updated: 2026/02/09 11:38:20 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	get_color(int iteration)
{
	if (iteration == 256)
		return (0x00000000);
	return ((iteration * 128) << 16 | ((iteration * 10) << 8) | ((iteration * 5) << 4));
}

void	display(t_fractol *fractol)
{
	int			x;
	int			y;
	int			iteration;
	t_complex	z_or_c;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			z_or_c = pixel_to_complex(fractol, x, y);
			if (fractol->name[0] == 'm')
				iteration = mandelbrot(z_or_c);
			else
				iteration = julia(z_or_c, fractol->julia_c);
			my_pixel_put(fractol, x, y, get_color(iteration));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connexion, fractol->mlx_windows,
		fractol->image_ptr, 0, 0);
}
