/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:53:07 by esalorin          #+#    #+#             */
/*   Updated: 2020/05/27 13:40:07 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 100

# define CBLACK "\x1B[30m"
# define CBLACKB "\x1B[1;30m"

# define CRED "\x1B[31m"
# define CREDB "\x1B[1;31m"

# define CGREEN "\x1B[32m"
# define CGREENB "\x1B[1;32m"

# define CYELLOW "\x1B[33m"
# define CYELLOWB "\x1B[1;33m"

# define CBLUE "\x1B[34m"
# define CBLUEB "\x1B[1;34m"

# define CMAGENTA "\x1B[35m"
# define CMAGENTAB "\x1B[1;35m"

# define CCYAN "\x1B[36m"
# define CCYANB "\x1B[1;36m"

# define CWHITE "\x1B[37m"
# define CWHITEB "\x1B[1;37m"

# define CRESET "\x1B[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_arraylen(char **array);

char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long value, int base, char c);
char				*ft_itoa_unsigned(unsigned long long value, int base,
					char c);
char				*ft_ftoa(long double n, int p);
char				*ft_joindel(char *s1, char *s2);
char				*ft_rmchr(char *s, int c);
char				*ft_rmescapes(char *s);

char				**ft_strsplit(char const *s, char c);
char				**ft_array_push(char **array, char *str, int index);
char				**ft_arraynew(size_t size);
char				**ft_array_merge(char **ar1, char **ar2);
char				**ft_arraydup(char **array);
char				**ft_arrayrem(char **array, int index);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_atoi(const char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_printf(const char *format, ...);
int					ft_print_csp(char c, va_list ap, int *m, int flag);
int					ft_print_dioux(char c, va_list ap, int f, int *m);
int					ft_print_flags(char *sub, va_list ap);
int					ft_dioux_flags(char *s, int i, va_list ap);
int					ft_print_double(va_list ap, int p, int len, int *m);
int					ft_double_flags(char *s, int i, va_list ap);
int					ft_csp_flags(char *s, int l, va_list ap);
int					ft_check_min(char *s);
int					get_next_line(const int fd, char **line);
int					ft_check_precision(char *s, int i);
int					ft_check_di(char *s, int *m);
int					ft_check_oux(char *s, char c, int *m);
int					ft_nbrlen(long long n);
int					ft_chrcount(const char *s, int c);
int					ft_strfound(const char *haystack, const char *needle);

long long			ft_atoi_base(const char *nbr, unsigned int base);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void				ft_check_flags(char *s, int *m);
void				ft_strswap(char **s1, char **s2);
void				ft_swap(long long *a, long long *b);
void				ft_arraydel(char **array);
void				ft_putarray(char **array);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t size);

t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
