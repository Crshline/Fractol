/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:06:19 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/17 13:43:38 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!cpy)
		return (NULL);
	return (ft_strcpy(cpy, str));
}

/*int	main(void)
{
	char *src = "hello";
	char *cpy = ft_strdup(src);

	printf("%s", cpy);
	free(cpy);
}*/
