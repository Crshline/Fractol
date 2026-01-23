/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:06:16 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/17 09:42:52 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isascii('0'));
	printf("%d\n", ft_isascii('9'));
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('D'));
	printf("%d\n", ft_isascii('#'));
}*/
