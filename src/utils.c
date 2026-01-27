/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:58:10 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/27 12:32:24 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

double	ft_atof(char *str)
{
	int		signe;
	double	result;
	double	decimal;

	result = 0.0;
	decimal = 1.0;
	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signe = -signe;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		decimal /= 10.0;
		result = result + (*str++ - 48) * decimal;
	}
	return (result * signe);
}

int	is_valid_number(char *str)
{
	int	i;
	int	digit;
	int	dot;

	i = 0;
	digit = 0;
	dot = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = 1;
		else if (str[i] == '.' && !dot)
			dot = 1;
		else
			return (0);
		i++;
	}
	return (digit);
}
