/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:51:25 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/14 12:06:11 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count(long n)
{
	size_t	size;

	size = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	string(long nb, char *str, size_t size)
{
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str[--size] = (nb % 10) + 48;
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	size_t	size;

	nb = n;
	size = count(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	string(nb, str, size);
	return (str);
}

/*int	main(void)
{
	printf("%s", ft_itoa(52));
}*/