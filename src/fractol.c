/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:01:20 by jukeurme          #+#    #+#             */
/*   Updated: 2026/02/02 09:29:01 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	error_msg(void)
{
	ft_putstr_fd("Nombre d'arguments invalides.\n", 2);
	ft_putstr_fd("Aide :\n", 2);
	ft_putstr_fd("mandelbrot\n", 2);
	ft_putstr_fd("julia <real> <imaginary>\n", 2);
}

void	my_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	int	offset;

	offset = (y * fractol->size_line) + (x * (fractol->bits_per_pixel / 8));
	*(unsigned int *)(fractol->pixel_ptr + offset) = color;
}

static void	preamble(t_fractol *fractol)
{
	fractol->zoom = 250.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	mlx_mouse_hook(fractol->mlx_windows, mouse, fractol);
	mlx_key_hook(fractol->mlx_windows, keysym, fractol);
	mlx_hook(fractol->mlx_windows, 17, 0, close_cross, fractol);
	display(fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connexion = mlx_init();
	if (fractol->mlx_connexion == NULL)
	{
		perror("connexion:");
		exit(1);
	}
	fractol->mlx_windows = mlx_new_window(fractol->mlx_connexion, 1000, 1000,
			"Fractol");
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
	preamble(fractol);
	mlx_loop(fractol->mlx_connexion);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.mlx_connexion = NULL;
	fractol.mlx_windows = NULL;
	fractol.image_ptr = NULL;
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot\0", 11) == 0)
		fractol.name = "mandelbrot";
	else if (ac == 4 && ft_strncmp(av[1], "julia\0", 6) == 0)
	{
		if (!is_valid_number(av[2]) || !is_valid_number(av[3]))
		{
			error_msg();
			return (1);
		}
		fractol.name = "julia";
		fractol.julia_c.a = ft_atof(av[2]);
		fractol.julia_c.b = ft_atof(av[3]);
	}
	else
	{
		error_msg();
		return (1);
	}
	fractol_init(&fractol);
	return (0);
}
