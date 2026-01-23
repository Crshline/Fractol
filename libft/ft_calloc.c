/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:06:03 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/18 10:02:17 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t tab, size_t len)
{
	void	*tmp;
	size_t	total_size;

	if (tab != 0 && len > __SIZE_MAX__ / tab)
		return (NULL);
	total_size = len * tab;
	tmp = malloc(total_size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, total_size);
	return (tmp);
}

/*int	main(void)
{
	int		*tab;
	int		i;

	tab = (int *)ft_calloc(5, sizeof(int));
	if (!tab)
		return (1);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/