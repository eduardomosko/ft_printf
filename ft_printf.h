/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:30:57 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/04 18:30:57 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

/*
** Represents possible argument conversions
*/

typedef enum e_conversion
{
	CONV_INT = 'i',
	CONV_DEC = 'd',
	CONV_HEXUP = 'X',
	CONV_HEXLOW = 'x',
	CONV_CHAR = 'c',
	CONV_STR = 's',
	CONV_UINT = 'u',
	CONV_PTR = 'p',
	CONV_NONE = '\0',
	CONV_PERCENT = '%',
}	t_conversion;

/*
** Formatted printing
*/

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list *ap);
int	ft_vdprintf(int fd, const char *format, va_list *ap);
int	ft_fputconv(int fd, t_conversion c, va_list *ap);

/*
** Integer printing
*/

int	ft_fputint(int fd, int n);
int	ft_fputuint(int fd, unsigned int n);

/*
** Hexadecimal printing
*/

int	ft_fputptr(int fd, const void *ptr);
int	ft_fputhex(int fd, unsigned int n);
int	ft_fputhex_upper(int fd, unsigned int n);

/*
** Char printing
*/

int	ft_fputchar(int fd, unsigned char c);
int	ft_fputstr(int fd, const char *s);

#endif /* FT_PRINTF_H */
