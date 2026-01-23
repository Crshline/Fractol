/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:20:21 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/14 11:20:24 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main()
{
	int fd = open("./test.txt", O_CREAT | O_WRONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (1);
	}
	ft_putchar_fd('c', fd);
}*/
