/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:53:38 by adeestev          #+#    #+#             */
/*   Updated: 2024/12/08 14:25:55 by adeestev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr_fd (n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	nbr1 = -2147483648;
	int	nbr2 = -42;
	int nbr3 = 0;
	int nbr4 = 42;
	int nbr5 = 871246561;
	int	fd = 1;

	ft_putnbr_fd(nbr1, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(nbr2, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(nbr3, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(nbr4, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(nbr5, fd);
	write(fd, "\n", 1);
	return (0);
}
*/