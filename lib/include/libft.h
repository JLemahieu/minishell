/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 00:31:58 by jlemahie          #+#    #+#             */
/*   Updated: 2018/09/18 07:24:05 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "includepf.h"
# define BUFFGNL_SIZE 500

char	*ft_strjoinsep(char const *s1, char c, char const *s2);
char	*ft_strtronc(char *s, char c);
void	ft_filltab(int *tab, int nb, size_t s);
int		ft_atoi(const char *nptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_mallocheck(size_t size);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_nbrlen(int n);
void	ft_putbuff(t_flagpf *flags, unsigned int n);
void	ft_putcharb(t_flagpf *flags, char c);
void	ft_putstrb(t_flagpf *flags, const char *str);
int		ft_putnstrb(t_flagpf *flags, const char *str, unsigned int n);
void	ft_putnbrb(t_flagpf *flags, int n);
int		ft_wnstrl(wchar_t *str, int n);
int		ft_wcharlen(wchar_t c);
int		ft_wstrlen(wchar_t *str, t_flagpf *flags);
int		ft_putnwstrb(t_flagpf *flags, wchar_t *str, int n);
void	ft_putwcharb(t_flagpf *flags, wchar_t c);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);
void	debug(int n);
char	*ft_strndup(const char *s, int i);
int		ft_putnstr(const char *str, int n);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strcat(char *dest, const char *src);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *s, int i);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		get_next_line(const int fd, char **line);

#endif
