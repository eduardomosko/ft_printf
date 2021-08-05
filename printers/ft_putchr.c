/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:25:41 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/04 21:25:41 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_fputchar(int fd, unsigned char c)
{
	char	res;

	res = c;
	return (write(fd, &res, 1));
}

int	ft_fputstr(int fd, const char *s)
{
	return (write(fd, s, ft_strlen(s)));
}
