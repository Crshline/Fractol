/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:58:10 by jukeurme          #+#    #+#             */
/*   Updated: 2026/02/02 09:26:08 by jukeurme         ###   ########.fr       */
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

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (str[i] == '\0');
}
