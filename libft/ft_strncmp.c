/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:06:24 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/17 13:22:48 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < len && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main(void)
{
	char s1[] = "hello";
	char s2[] = "heLlo";

	printf("%d", ft_strncmp(s1, s2, 4));
}*/
