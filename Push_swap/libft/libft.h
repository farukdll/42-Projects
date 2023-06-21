#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<unistd.h>

typedef struct s_data
{
	int	*a;
	int	a_size;

	int	*b;
	int	b_size;
}	t_data;

size_t	ft_strlen(const char *s);
size_t	w_l(char const *s, char c);
size_t	w_c(char const *s, char c);
int		ft_atoi(const char *str, t_data *x);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
