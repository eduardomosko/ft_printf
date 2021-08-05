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

const char	*g_lookup = "0123456789abcdef";
const char	*g_LOOKUP = "0123456789ABCDEF";

static size_t	ft_format_hex(char *out, size_t n, const char *lookup)
{
	size_t	count;

	count = 1;
	*out = '0';
	while (n)
	{
		*out++ = n % 16;
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_fputptr(int fd, const void *ptr)
{
	char	buf[sizeof(ptr) * 2 + 2];
	size_t	to_write;

	buf[0] = '0';
	buf[1] = 'x';
	to_write = 2 + ft_format_hex(buf + 2, (size_t)ptr, g_lookup);
	return (write(fd, buf, to_write));
}

int	ft_fputhex(int fd, unsigned int n)
{
	char	buf[sizeof(n) * 2];
	size_t	to_write;

	to_write = ft_format_hex(buf, n, g_LOOKUP);
	return (write(fd, buf, to_write));
}

int	ft_fputHEX(int fd, unsigned int n)
{
	char	buf[sizeof(n) * 2];
	size_t	to_write;

	to_write = ft_format_hex(buf, n, g_lookup);
	return (write(fd, buf, to_write));
}
