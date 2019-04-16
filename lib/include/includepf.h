/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includepf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:08:13 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/19 17:12:17 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDEPF_H
# define INCLUDEPF_H
# define ABS(Value) (((Value) < 0 ? -(Value) : (Value)))
# define BUFFPF_MAX 500

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

typedef	struct	s_indicpf
{
	int	space;
	int	sign;
	int	left;
	int	zero;
	int	diese;
}				t_indicpf;

typedef	struct	s_flagpf
{
	t_indicpf		indic;
	int				large;
	int				preci;
	int				taille;
	int				flag;
	int				ptr;
	char			buff[BUFFPF_MAX];
	unsigned int	i;
	int				backup;
}				t_flagpf;

uintmax_t		ft_taillnbru(va_list *args, t_flagpf *flags);
char			*ft_putnbru(intmax_t n);
intmax_t		ft_taillnbr(va_list *args, t_flagpf *flags);
int				ft_patoi(char *str);
char			*ft_itoabase(uintmax_t n, char *sym);
void			ft_set_flags(t_flagpf *flags);
int				ft_printnret(int ret, const char *restrict format, ...);
int				ft_printf(const char *restrict format, ...);
int				ft_inner_printf(const char *format, va_list *args, int size,
		t_flagpf *flags);
int				ft_parse(const char **format, va_list *args, t_flagpf *flags);
char			*ft_parse_flag(char **format, t_flagpf *flags, char *test);
char			*ft_parse_taille(char **format, t_flagpf *flags);
char			*ft_parse_preci(char **format, t_flagpf *flags, va_list *args);
char			*ft_parse_large(char **format, t_flagpf *flags, va_list *args);
char			*ft_parse_indic(char **format, t_flagpf *flags);
int				ft_execpf(va_list *args, t_flagpf *flags);
int				ft_fill(int i, int size, char sym, t_flagpf *flags);

#endif
