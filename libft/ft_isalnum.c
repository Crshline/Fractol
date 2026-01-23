/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:06:10 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/11 10:54:45 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*#include <stdio.h>
int main()
{
    printf("%d\n", ft_isalnum('a'));
    printf("%d\n", ft_isalnum('S'));
    printf("%d\n", ft_isalnum('0'));
    printf("%d\n", ft_isalnum('9'));
    printf("%d\n", ft_isalnum(' '));
    printf("%d\n", ft_isalnum('\n'));
}*/
