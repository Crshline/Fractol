/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:21:24 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/17 10:38:16 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src || len == 0)
		return (dest);
	if (t_dest > t_src)
	{
		while (len-- > 0)
			t_dest[len] = t_src[len];
	}
	else
	{
		while (i < len)
		{
			t_dest[i] = t_src[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	unsigned char	str[] = "abcdef";
	unsigned char	str2[] = "abcdef";

	printf("%s : %p\n", str, str);
	ft_memmove(str + 2, str, 3);
	printf("%s : %p\n", str, str);
	printf("%s\n", str2);
	ft_memmove(str2 + 2, str2, 3);
	printf("%s\n", str2);
}*/
