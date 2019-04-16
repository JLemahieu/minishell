/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:05:34 by jlemahie          #+#    #+#             */
/*   Updated: 2018/07/20 01:05:35 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "includepf.h"

int	ft_print_s(va_list *args, t_flagpf *flags);
int	ft_print_ss(va_list *args, t_flagpf *flags);
int	ft_print_p(va_list *args, t_flagpf *flags);
int	ft_print_d(va_list *args, t_flagpf *flags);
int	ft_print_dd(va_list *args, t_flagpf *flags);
int	ft_print_o(va_list *args, t_flagpf *flags);
int	ft_print_oo(va_list *args, t_flagpf *flags);
int	ft_print_u(va_list *args, t_flagpf *flags);
int	ft_print_uu(va_list *args, t_flagpf *flags);
int	ft_print_x(va_list *args, t_flagpf *flags);
int	ft_print_xx(va_list *args, t_flagpf *flags);
int	ft_print_c(va_list *args, t_flagpf *flags);
int	ft_print_cc(va_list *args, t_flagpf *flags);
int	ft_print_perc(va_list *args, t_flagpf *flags);
int ft_print_inv(va_list *args, t_flagpf *flags);

#endif
