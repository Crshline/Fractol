/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:00:56 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/14 14:23:41 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (is_in_set(s1[start], set))
		start++;
	while (is_in_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

/*int	main(void)
{
	char s1[] = "ababaaaMy name is Julienbbaaabbad";
	char set[] = "abd";

	printf("%s", ft_strtrim(s1, set));
}*/