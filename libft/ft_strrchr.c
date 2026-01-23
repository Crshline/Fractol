/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:05:23 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/18 12:14:40 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (((char *)&str[i]));
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	int c = 'a';
	char str[] = "cauaaaaaaaou";

	printf("%s", ft_strrchr(str, c));
}*/
