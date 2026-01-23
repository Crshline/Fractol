/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:57:18 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/19 08:51:45 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s && *s != sep)
			s++;
	}
	return (count);
}

int	retrieval(char **tab, char const *s, char sep)
{
	char const	*tmp;
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*tmp && *tmp != sep)
			tmp++;
		if (tmp > s)
		{
			tab[i] = ft_substr(s, 0, tmp - s);
			if (!tab[i])
				return (0);
			i++;
			s = tmp;
		}
	}
	tab[i] = NULL;
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	if (!retrieval(new, s, c))
	{
		free_tab(new);
		return (NULL);
	}
	return (new);
}

/*#include <stdio.h>
 int	main(void)
 {
	char	str[] = "a	b b";
	char	**tab = ft_split(str, ' ');
	size_t	i = 0;

	while (tab[i] != NULL)
		printf("- %s\n", tab[i++]);

	while(tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (0);
 }*/