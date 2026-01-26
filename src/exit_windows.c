/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:52:37 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/26 12:33:08 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	clean_exit(t_fractol *fractol)
{
	if (fractol->image_ptr)
		mlx_destroy_window(fractol->mlx_connexion, fractol->image_ptr);
	if (fractol->mlx_windows)
		mlx_destroy_window(fractol->mlx_connexion, fractol->mlx_windows);
	if (fractol->mlx_connexion)
	{
		mlx_destroy_display(fractol->mlx_connexion);
		free(fractol->mlx_connexion);
	}
	exit(0);
	return (0);
}

int	close_cross(t_fractol *fractol)
{
	clean_exit(fractol);
	return (0);
}
