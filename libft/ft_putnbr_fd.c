/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukeurme <jukeurme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:30:15 by jukeurme          #+#    #+#             */
/*   Updated: 2025/11/17 13:13:39 by jukeurme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + 48, fd);
}

/*int main()
{
	int fd = open("./test.txt", O_CREAT | O_WRONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Cannot read file.\n", 18);
		return (1);
	}
	ft_putnbr_fd(15, fd);
}*/