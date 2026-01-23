/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:06:22 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/14 15:37:13 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include <stdio.h>
int main()
{
    printf("%d\n", ft_isprint('0'));
    printf("%d\n", ft_isprint('9'));
    printf("%d\n", ft_isprint('q'));
    printf("%d\n", ft_isprint('F'));
    printf("%d\n", ft_isprint('#'));
}*/
