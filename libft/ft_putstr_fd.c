/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:20:04 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/14 11:20:05 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*int main()
{
	char s[] = "Je suis ici";
	int fd = open("./test.txt", O_CREAT | O_WRONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (1);
	}
	ft_putstr_fd(s, fd);
}*/