/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:59:41 by pascal        #+#    #+#                 */
/*   Updated: 2021/07/30 14:33:43 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);

long			ft_abs(long num);
char			*ft_decitohex(unsigned long long number);
void			*ft_memdup(const void *src, size_t len);
long long		ft_power(int n, int power);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
char			*ft_ulltoa(unsigned long long number);
size_t			ft_unumlen(unsigned long number);
size_t			ft_numlen(long number);
char			ft_iswhitespace(const char ch);
char			*ft_strnjoin(size_t n, ...);
char			**ft_split_set(char *str, char *set);
char			ft_charcmpset(char ch, char *set);
double			ft_atof(char *str);
char			*ft_dtoa(double n);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_split_free(char **splits);

int				get_next_line(int fd, char **line);

#endif
