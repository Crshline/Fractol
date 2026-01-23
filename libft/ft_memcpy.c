/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:42:09 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/18 14:31:46 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0 || (!dest && !src))
		return (dest);
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	unsigned char	src[10] = "hello";
	unsigned char	dest[10];

	ft_memcpy(dest, src, 0);
	printf("src : %s\ndest : %s\n", src, dest);
}*/
