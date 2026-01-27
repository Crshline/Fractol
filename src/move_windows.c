/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:32:32 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/27 10:57:24 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	keysym(int keysym, t_fractol *fractol)
{
	if (keysym == 65307)
		clean_exit(fractol);
	else if (keysym == 65362)
	{
		fractol->offset_y = fractol->offset_y - (50.0 / fractol->zoom);
		render(fractol);
	}
	else if (keysym == 65361)
	{
		fractol->offset_x = fractol->offset_x - (50.0 / fractol->zoom);
		render(fractol);
	}
	else if (keysym == 65364)
	{
		fractol->offset_y = fractol->offset_y + (50.0 / fractol->zoom);
		render(fractol);
	}
	else if (keysym == 65363)
	{
		fractol->offset_x = fractol->offset_x + (50.0 / fractol->zoom);
		render(fractol);
	}
	return (0);
}

int	mouse(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom = fractol->zoom * 1.1;
		render(fractol);
	}
	else if (button == 5)
	{
		fractol->zoom = fractol->zoom / 1.1;
		render(fractol);
	}
	return (0);
}
