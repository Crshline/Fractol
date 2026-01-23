/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:39:57 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/07 16:24:01 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('2'));
	printf("%d\n", ft_isdigit('q'));
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", ft_isdigit('9'));
}*/
