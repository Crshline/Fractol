/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:01:20 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/26 13:28:10 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	my_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	int	offset;

	offset = (y * fractol->size_line) + (x * (fractol->bits_per_pixel / 8));
	*(unsigned int *)(fractol->pixel_ptr + offset) = color;
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connexion = mlx_init();
	fractol->zoom = 250.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	if (fractol->mlx_connexion == NULL)
	{
		perror("connexion:");
		exit(1);
	}
	fractol->mlx_windows = mlx_new_window(fractol->mlx_connexion, 1000, 1000,
			"Fractol test");
	if (fractol->mlx_windows == NULL)
	{
		perror("windows:");
		exit(1);
	}
	fractol->image_ptr = mlx_new_image(fractol->mlx_connexion, 1000, 1000);
	if (fractol->image_ptr == NULL)
	{
		clean_exit(fractol);
		perror("image:");
		exit(1);
	}
	fractol->pixel_ptr = mlx_get_data_addr(fractol->image_ptr,
			&fractol->bits_per_pixel, &fractol->size_line,
			&fractol->octet_order);
	render(fractol);
	mlx_mouse_hook(fractol->mlx_windows, mouse, fractol);
	mlx_key_hook(fractol->mlx_windows, keysym, fractol);
	mlx_hook(fractol->mlx_windows, 17, 0, close_cross, fractol);
	mlx_loop(fractol->mlx_connexion);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;
	if(ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
		fractol.name = "mandelbrot";
	else if(ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		fractol.name = "julia";
		fractol.julia_c.a = atof(av[2]);
		fractol.julia_c.b = atof(av[3]);
	}
	else
	{
		write(1, "Nombre d'arguments invalides :\n", 32);
		write(1, "mandelbrot\n", 12);
		write(1, "julia <real> <imaginary>\n", 26);
		return(1);
	}
	fractol_init(&fractol);
	return (0);
}
