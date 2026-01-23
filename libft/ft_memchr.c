/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:50:24 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/17 13:57:54 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	int				c;
	unsigned char	str[] = "healo";

	c = '\0';
	printf("%s", (unsigned char *)ft_memchr(str, c, 10));
}*/
