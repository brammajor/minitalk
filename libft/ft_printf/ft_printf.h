/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmajor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:28:03 by brmajor           #+#    #+#             */
/*   Updated: 2023/06/19 10:05:19 by brmajor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft.h"

int	ft_printf(const char *input, ...);
int	ft_strchr_p(const char *s, char c);
int	ft_intlen(int i);
int	uintlen(unsigned int i);
int	ft_hexlen(long long i);
int	putcharf(int c);
int	putstrf(char *str);
int	putptrf(unsigned long long x);
int	putnbrf(int i);
int	putdecf(unsigned int i);
int	puthexf(unsigned int i, char c);
int	puthexlongf(unsigned long long i, char c);

#endif
