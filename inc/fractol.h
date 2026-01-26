/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:24:40 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/26 13:22:23 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_complex
{
	double		a;
	double		b;
}				t_complex;

typedef struct s_fractol
{
	void		*mlx_connexion;
	void		*mlx_windows;

	void		*image_ptr;
	char		*pixel_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			octet_order;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_complex	julia_c;
	char		*name;

}				t_fractol;

int				clean_exit(t_fractol *fractol);
int				close_cross(t_fractol *fractol);
int				keysym(int keysym, t_fractol *fractol);
int				mouse(int button, int x, int y, t_fractol *fractol);
t_complex		pixel_to_complex(t_fractol *fractol, int x, int y);
int				mandelbrot(t_complex c);
int				get_color(int iteration);
void			render(t_fractol *fractol);
void			my_pixel_put(t_fractol *fractol, int x, int y, int color);
void			fractol_init(t_fractol *fractol);

#endif
