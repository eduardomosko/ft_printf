/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:22:04 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/04 21:22:04 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_format_uint(char *out, unsigned int n)
{
	size_t			count;
	unsigned int	nb;

	nb = n;
	*out = '0';
	count = (n == 0);
	while (nb)
	{
		nb /= 10;
		count++;
	}
	out += count;
	while (n)
	{
		*--out = '0' + n % 10;
		n /= 10;
	}
	return (count);
}

int	ft_fputint(int fd, int n)
{
	char			buf[sizeof(n) / 4 * 10 + 1];
	size_t			to_write;
	int				negative;
	unsigned int	num;

	num = n;
	negative = n < 0;
	if (negative)
	{
		num *= -1;
		*buf = '-';
	}
	to_write = ft_format_uint(buf + negative, num) + negative;
	return (write(fd, buf, to_write));
}

int	ft_fputuint(int fd, unsigned int n)
{
	char	buf[sizeof(n) / 4 * 10];
	size_t	to_write;

	to_write = ft_format_uint(buf, n);
	return (write(fd, buf, to_write));
}
