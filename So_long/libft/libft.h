#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *b, size_t n);
char	*ft_itoa(int n);
#endif
