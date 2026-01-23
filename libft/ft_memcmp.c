/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:06:10 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/18 09:56:47 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i == len)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*int	main(void)
{
	char s1[] = "hello";
	char s2[] = "hello";

	printf("%d", ft_memcmp(s1, s2, 4));
}*/
