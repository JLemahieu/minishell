/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 03:11:38 by jlemahie          #+#    #+#             */
/*   Updated: 2018/05/25 05:10:55 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includepf.h"
#include "../include/print.h"
#include "../include/libft.h"

int	(*g_list_flagpf[16])(va_list*, t_flagpf*) =
{
	ft_print_s, \
	ft_print_x, \
	ft_print_xx, \
	ft_print_c, \
	ft_print_o, \
	ft_print_d, \
	ft_print_d, \
	ft_print_u, \
	ft_print_oo, \
	ft_print_uu, \
	ft_print_dd, \
	ft_print_p, \
	ft_print_cc, \
	ft_print_ss, \
	ft_print_perc, \
	ft_print_inv \
};

char		*ft_putnbru(intmax_t n)
{
	static	char	buff[50];
	static	char	sym[] = "0123456789";
	char			*ptr;
	uintmax_t		m;

	if (n < 0)
		m = -n;
	else
		m = n;
	if (m == 0)
		return ("0");
	ptr = &buff[49];
	*ptr = 0;
	while (m != 0)
	{
		*--ptr = sym[m % 10];
		m = m / 10;
	}
	return (ptr);
}

char		*ft_itoabase(uintmax_t n, char *sym)
{
	static	char	buff[50];
	char			*ptr;
	int				base;

	if (n == 0)
		return ("0");
	base = ft_strlen(sym);
	ptr = &buff[49];
	*ptr = 0;
	while (n != 0)
	{
		*--ptr = sym[n % base];
		n = n / base;
	}
	return (ptr);
}

int			ft_execpf(va_list *args, t_flagpf *flags)
{
	int ret;

	ret = g_list_flagpf[flags->flag](args, flags);
	if (ret != -1)
		flags->backup = flags->i;
	return (ret);
}
