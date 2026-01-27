/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:58:10 by jukeurme          #+#    #+#             */
/*   Updated: 2026/01/27 11:14:00 by jukeurme         ###   ########.fr       */
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

	i = 0;
	digit = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = 1;
		else if (str[i] != '.')
			return (0);
		i++;
	}
	return (digit);
}
