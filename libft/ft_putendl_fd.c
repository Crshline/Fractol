/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:31:00 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/14 11:31:01 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
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
	ft_putendl_fd(s, fd);
}*/