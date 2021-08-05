/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:32:44 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/04 18:32:44 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	ap;

	va_start(ap, format);
	printed = ft_vprintf(format, &ap);
	va_end(ap);
	return (printed);
}

int	ft_vprintf(const char *format, va_list *ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list *ap)
{
	const char	*it;
	int			count;
	int			ret;

	count = 0;
	it = format;
	while (*it)
	{
		ret = 0;
		if (*it == '%' && *++it)
		{
			ret = ft_fputconv(fd, *it, ap);
		}
		else
		{
			ret = ft_fputchar(fd, *it);
		}
		if (ret < 0)
			return (ret);
		count += ret;
		it++;
	}
	return (count);
}

int	ft_fputconv(int fd, t_conversion c, va_list *ap)
{
	if (c == CONV_CHAR)
		return (ft_fputchar(fd, va_arg(*ap, int)));
	if (c == CONV_STR)
		return (ft_fputstr(fd, va_arg(*ap, const char *)));
	if (c == CONV_PTR)
		return (ft_fputptr(fd, va_arg(*ap, void *)));
	if (c == CONV_DEC || c == CONV_INT)
		return (ft_fputint(fd, va_arg(*ap, int)));
	if (c == CONV_UINT)
		return (ft_fputuint(fd, va_arg(*ap, unsigned int)));
	if (c == CONV_HEXLOW)
		return (ft_fputhex(fd, va_arg(*ap, unsigned int)));
	if (c == CONV_HEXUP)
		return (ft_fputHEX(fd, va_arg(*ap, unsigned int)));
	if (c == CONV_PERCENT)
		return (ft_fputchar(fd, '%'));
	if (c == CONV_NONE)
		return (0);
	return (-1);
}
