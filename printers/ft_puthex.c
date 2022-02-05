/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:23:47 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/04 21:23:47 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_format_hex(char *out, size_t n, const char *lookup)
{
	size_t	count;
	size_t	nb;

	nb = n;
	*out = '0';
	count = (n == 0);
	while (nb)
	{
		nb /= 16;
		count++;
	}
	out += count;
	while (n)
	{
		*--out = lookup[n % 16];
		n /= 16;
	}
	return (count);
}

int	ft_fputptr(int fd, const void *ptr)
{
	char	buf[sizeof(ptr) * 2 + 2];
	size_t	to_write;

	buf[0] = '0';
	buf[1] = 'x';
	to_write = 2 + ft_format_hex(buf + 2, (size_t)ptr, "0123456789abcdef");
	return (write(fd, buf, to_write));
}

int	ft_fputhex(int fd, unsigned int n)
{
	char	buf[sizeof(n) * 2];
	size_t	to_write;

	to_write = ft_format_hex(buf, n, "0123456789abcdef");
	return (write(fd, buf, to_write));
}

int	ft_fputhex_upper(int fd, unsigned int n)
{
	char	buf[sizeof(n) * 2];
	size_t	to_write;

	to_write = ft_format_hex(buf, n, "0123456789ABCDEF");
	return (write(fd, buf, to_write));
}
