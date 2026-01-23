/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:38:25 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/11 14:10:45 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (len <= dest_len)
		return (len + src_len);
	while (src[i] && (dest_len + i + 1) < len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*int	main(void)
{
	char dest[] = "Salut";
	size_t ret;

	ret = ft_strlcat(dest, "World", 3);
	printf("%s (%zu)\n", dest, ret);
}*/
